#include "malloc.h"
#include <stdlib.h>
#include <sys/cdefs.h>
#include <sys/simpl_builtin.h>

uint32_t __hidden bitmap[BITMAP_SIZE / 32] = {0};
void *__hidden    memory_pool = NULL;
Block __hidden   *freelist = NULL;
Block __hidden   *bins[NUM_BINS] = {NULL};
int __hidden      allocated_blocks = 0;

/// use in the __libc_start_main to init the malloc memory pool
void initialize_memory_pool()
{
    memory_pool =
        mmap(NULL, MEMORY_POOL_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (memory_pool == MAP_FAILED)
    {
        // perror("Failed to initialize memory pool");
        exit(EXIT_FAILURE);
    }

    freelist = (Block *)memory_pool;
    freelist->size = MEMORY_POOL_SIZE - BLOCK_SIZE;
    freelist->free = 1;
    freelist->is_mmap = 0;
    freelist->next = NULL;
    freelist->start_canary = CANARY_START_VALUE;
    freelist->end_canary = CANARY_END_VALUE;
    freelist->aligned_address = (void *)((uintptr_t)memory_pool + BLOCK_SIZE);
}

int get_bin_index(size_t size)
{
    if (size <= 32)
        return size / BLOCK_UNIT_SIZE;
    if (size > 32 && size <= 512)
        return 32 + (size / 64);
    return 63;
}

/*
 * Function to split a block into two blocks
 * block: block to be split
 * size: size of the memory to be allocated
 * this function is called when the block is larger than the requested size
 * the block is split into two blocks, one of the requested size and the other of the remaining size
 */

static inline void split_block(Block *block, size_t size, size_t alignment)
{
    size_t remaining_size = block->size - size - BLOCK_SIZE;
    if (remaining_size < BLOCK_SIZE)
        return;

    uintptr_t new_block_address = (uintptr_t)block + BLOCK_SIZE + size;
    uintptr_t aligned_new_block_address = simpl_align_up(new_block_address, alignment);

    if ((aligned_new_block_address - new_block_address) > remaining_size)
        return;

    Block *new_block = (Block *)aligned_new_block_address;
    new_block->size = remaining_size - (aligned_new_block_address - new_block_address);
    new_block->free = 1;
    new_block->next = block->next;
    block->size = size;
    block->next = new_block;
}

/*
 * this function call sbrk to allocate memory
 * last: last block in the freelist
 * size: size of the memory to be allocated
 * alignment: alignment of the memory to be allocated
 * only be used if the requested size is larger than the block size
 * Returns: pointer to the allocated memory
 */

Block *request_space(Block *last, size_t size, size_t alignment)
{
    if (simpl_expect(size == 0, 0))
        return NULL;

    size_t page_size = PAGESIZE; // sysconf(_SC_PAGESIZE);
    size_t total_size = simpl_align_up(size + sizeof(Block), page_size);
    if ((alignment & (alignment - 1)) != 0)
    {
        return NULL;
    }
    void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
    {
        return NULL;
    }
    void *free_block = find_free_block(size, alignment);
    if (free_block)
    {
        uintptr_t block_addr = (uintptr_t)free_block - sizeof(Block);
        Block    *block = (Block *)block_addr;

        if ((uintptr_t)block < (uintptr_t)memory_pool ||
            (uintptr_t)block + sizeof(Block) > (uintptr_t)memory_pool + MEMORY_POOL_SIZE)
        {
            return NULL;
        }

        if (block->size > size + sizeof(Block))
        {
            split_block(block, size, alignment);
        }

        block->size = size;
        block->free = 0;
        block->aligned_address = free_block;
        return block;
    }

    __unused size_t alignment_mask = alignment - 1; // todo

    total_size = (total_size + page_size - 1) & ~(page_size - 1);
    void *request =
        mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    // madvise(request, total_size, MADV_HUGEPAGE);
    if (request == MAP_FAILED)
    {
        return NULL;
    }

    uintptr_t raw_addr = (uintptr_t)request;
    uintptr_t aligned_addr = simpl_align_up(raw_addr + sizeof(Block), alignment);

    if (aligned_addr + size > raw_addr + total_size)
    {
        // if (munmap(request, total_size) == -1)
        // perror("[ERROR] munmap failed");
        return NULL;
    }

    Block *block = (Block *)(aligned_addr - sizeof(Block));

    if ((uintptr_t)block < raw_addr ||
        (uintptr_t)block + sizeof(Block) + size > raw_addr + total_size)
    {
        munmap(request, total_size);
        return NULL;
    }

    block->size = size;
    block->free = 0;
    block->is_mmap = 1;
    block->next = NULL;
    block->aligned_address = (void *)simpl_align_up(aligned_addr, alignment);

    if (last)
        last->next = block;
    else if (!freelist)
        freelist = block;

    return block;
}

/*
 * this function call mmap to allocate memory
 * size: size of the memory to be allocated
 * alignment: alignment of the memory to be allocated
 * Returns: pointer to the allocated memory
 */

__attribute__((hot)) void *request_space_mmap(size_t size, size_t alignment)
{
    size_t total_size = size + BLOCK_SIZE + alignment - 1;
    void  *mapped_memory =
        mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    if (mapped_memory == MAP_FAILED)
        return NULL;

    if (mprotect(mapped_memory, total_size, PROT_READ | PROT_WRITE) == -1)
    {
        // perror("mprotect failed");
        munmap(mapped_memory, total_size);
        return NULL;
    }

    uintptr_t raw_addr = (uintptr_t)mapped_memory;
    uintptr_t aligned_addr = simpl_align_up(raw_addr + BLOCK_SIZE, alignment);
    Block    *block = (Block *)(aligned_addr - sizeof(Block));

    block->size = size;
    block->next = NULL;
    block->free = 0;
    block->is_mmap = 1;
    block->aligned_address = (void *)aligned_addr;

    allocated_blocks++;
    return block->aligned_address;
}

void *__malloc_simpl(size_t size)
{
    if (size == 0)
        return NULL;

    static int is_initialized = 0;
    if (!is_initialized)
    {
        initialize_memory_pool();
        is_initialized = 1;
    }

    size = simpl_align_up(size, ALIGNMENT);

    if (size > MMAP_THRESHOLD)
    {
        size_t total_size = size + BLOCK_SIZE;
        void  *addr =
            mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        // madvise(addr, total_size, MADV_SEQUENTIAL);
        if (addr == MAP_FAILED)
        {
            // perror("mmap failed");
            return NULL;
        }
        Block *block = (Block *)addr;
        block->size = size;
        block->free = 0;
        block->is_mmap = 1;
        block->next = NULL;
        block->aligned_address = (void *)(block + 1);
        return block->aligned_address;
    }

    Block *block = NULL;
    int    bin_index = get_bin_index(size);

    for (int i = bin_index; i < NUM_BINS; i++)
    {
        if (bins[i] != NULL)
        {
            block = bins[i];
            bins[i] = block->next;
            break;
        }
    }

    if (block)
    {
        if (block->size >= size + BLOCK_SIZE)
        {
            split_block(block, size, ALIGNMENT);
        }
        block->free = 0;
        return block->aligned_address;
    }

    block = request_space(freelist, size, ALIGNMENT);
    if (!block)
        return NULL;

    if ((uintptr_t)block->aligned_address < (uintptr_t)memory_pool ||
        (uintptr_t)block->aligned_address + size > (uintptr_t)memory_pool + MEMORY_POOL_SIZE)
    {
        return NULL;
    }

    return block->aligned_address;
}


libc_hidden_alias(__malloc, __malloc_simpl)
simpl_weak_alias(malloc, __malloc_simpl);
