#include "malloc.h"
#include <simplv.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/simpl_builtin.h>

/*
 * Function to find a free block in the freelist
 * size: size of the memory to be allocated
 * alignment: alignment of the memory to be allocated
 * Returns: pointer to the allocated memory
 */

static uint32_t bitmap[BITMAP_SIZE / 32];
static void    *memory_pool = NULL;


void *ARCH_SYM(find_free_block)(size_t size, size_t alignment)
{
    if (!memory_pool || size == 0 || size > MEMORY_POOL_SIZE)
        return NULL;

    size_t units_needed = (size + BLOCK_UNIT_SIZE - 1) / BLOCK_UNIT_SIZE;
    vec    mask = v256b_set1_char(0);

    for (size_t i = 0; i < BITMAP_SIZE / 256; i++)
    {
        vec bitmap_chunk = v256b_loadu((uvec *)&bitmap[i * 8]);
        vec inverted_chunk = v256b_andnot(bitmap_chunk, mask);
        int bitmask = v32c_movemask(inverted_chunk);
        if (bitmask)
        {
            for (int j = 0; j < 8; j++)
            {
                size_t current_start = i * 8 + j;

                if (current_start == 0)
                    continue;

                if (current_start + units_needed > BITMAP_SIZE)
                    continue;

                uint32_t bits = ~bitmap[current_start];
                while (bits)
                {
                    int       free_bit = simpl_ctz(bits);
                    size_t    start = (current_start * 32) + free_bit;
                    uintptr_t addr = (uintptr_t)memory_pool + start * BLOCK_UNIT_SIZE;

                    if (addr + size > (uintptr_t)memory_pool + MEMORY_POOL_SIZE)
                        break;

                    int enough_space = 1;
                    for (size_t k = 0; k < units_needed; k++)
                    {
                        size_t idx = start + k;
                        if (bitmap[idx / 32] & (1U << (idx & 31)))
                        {
                            enough_space = 0;
                            break;
                        }
                    }

                    if (enough_space)
                    {
                        for (size_t k = 0; k < units_needed; k++)
                        {
                            size_t idx = start + k;
                            bitmap[idx / 32] |= (1U << (idx & 31));
                        }

                        uintptr_t aligned_addr = simpl_align_up(addr, alignment);
                        if (aligned_addr + size > (uintptr_t)memory_pool + MEMORY_POOL_SIZE)
                        {
                            return NULL;
                        }
                        return (void *)aligned_addr;
                    }

                    bits &= ~(1U << free_bit);
                }
            }
        }
    }
    return NULL;
}
