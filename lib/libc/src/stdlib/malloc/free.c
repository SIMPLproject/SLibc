
#include "malloc.h"

extern uint32_t __hidden bitmap[BITMAP_SIZE / 32];
extern void *__hidden    memory_pool;
extern Block __hidden   *freelist;
extern Block __hidden   *bins[NUM_BINS];

static void insert_sorted(Block *block)
{
    Block *current = freelist;
    Block *prev = NULL;

    while (current && current->size < block->size)
    {
        prev = current;
        current = current->next;
    }

    block->next = current;
    if (prev)
    {
        prev->next = block;
    } else
    {
        freelist = block;
    }
}

static void mark_bits(uintptr_t start, size_t size, int value)
{
    size_t start_idx = (start - (uintptr_t)memory_pool) / BLOCK_UNIT_SIZE;
    size_t end_idx = start_idx + (size / BLOCK_UNIT_SIZE);

    for (size_t i = start_idx; i < end_idx; i++)
    {
        if (value)
            bitmap[i / 32] |= (1U << (i % 32));
        else
            bitmap[i / 32] &= ~(1U << (i % 32));
    }
}

static void insert_into_bin(Block *block)
{
    if (!block || !block->free)
        return;

    int index = get_bin_index(block->size);
    block->next = bins[index];
    bins[index] = block;

    uintptr_t block_start = (uintptr_t)block + BLOCK_SIZE;
    mark_bits(block_start, block->size, 0);
}

static void coalesce_free_blocks()
{
    Block          *current = freelist;
    __unused Block *prev = NULL; // todo

    while (current && current->next)
    {
        uintptr_t current_end = (uintptr_t)current + BLOCK_SIZE + current->size;
        uintptr_t next_start = (uintptr_t)current->next;

        if (current_end == next_start && current->free && current->next->free)
        {
            size_t merged_size = current->size + BLOCK_SIZE + current->next->size;

            mark_bits(current_end, current->next->size, 0);
            mark_bits((uintptr_t)current, merged_size, 1);

            current->size = merged_size;
            current->next = current->next->next;

            continue;
        }

        prev = current;
        current = current->next;
    }
}

static void improved_free(void *ptr)
{
    if (!ptr)
        return;

    Block *block = (Block *)((uintptr_t)ptr - sizeof(Block));

    if (block->free)
    {
        return;
    }

    if (block->is_mmap)
    {
        size_t total_size = block->size + sizeof(Block);
        (void)total_size;
        // if (munmap(block, total_size)) {
        //     perror("munmap failed");
        // }
        return;
    }

    if ((uintptr_t)block < (uintptr_t)memory_pool ||
        (uintptr_t)block > (uintptr_t)memory_pool + MEMORY_POOL_SIZE)
    {
        return;
    }

    block->free = 1;

    if (block->size <= MAX_BIN_SIZE)
    {
        insert_into_bin(block);
    } else
    {
        insert_sorted(block);
    }
    if (block->size > MAX_BIN_SIZE)
    {
        coalesce_free_blocks();
    }
}

void free(void *ptr)
{

    improved_free(ptr);
    coalesce_free_blocks();
}
