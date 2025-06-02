#include "include.h"
#include <stdlib.h>
#include <sys/simpl_builtin.h>

Block __hidden *freelist = NULL;
int __hidden    allocated_blocks = 0;
size_t __hidden block_size[] = {16,  32,  48,  64,  80,  96,  112, 128,
                                144, 160, 176, 192, 208, 224, 240, 256};
Block __hidden *bins[BIN_COUNT] = {NULL};
Block          *is_mmap = NULL;


__attribute__((hot, flatten, always_inline)) inline void *__slibc_malloc(size_t size)
{
    if (simpl_expect(size == 0, 0))
        return NULL;
    size = simpl_align_up(size, ALIGNMENT);
    Block *block = NULL;
    if (size <= BIN_MAX_SIZE)
    {
        int bin_index = size / ALIGNMENT - 1;
        if (bin_index >= 0 && bin_index < BIN_COUNT && bins[bin_index])
        {
            Block *block = bins[bin_index];
            bins[bin_index] = block->next;
            block->free = 0;
            return block->aligned_address;
        }
    }

    if (size >= MMAP_THRESHOLD)
        return request_space_mmap(size, ALIGNMENT);
    else
    {
        if (!freelist)
        {
            block = request_space(NULL, size, ALIGNMENT);
            freelist = block;
        } else
        {
            Block *last = freelist;
            block = find_free_block(size, ALIGNMENT);
            if (block)
            {
                if (block->size >= size + BLOCK_SIZE)
                    split_block(block, size, ALIGNMENT);
                block->free = 0;
            } else
                block = request_space(last, size, ALIGNMENT);
        }
    }
    return simpl_assume_aligned(block->aligned_address, ALIGNMENT);
}


libc_hidden_alias(__malloc, __slibc_malloc)
simpl_weak_alias(malloc, __slibc_malloc)
