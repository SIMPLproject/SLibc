#include "malloc.h"
#include <stdlib.h>
#include <config.h>
#include <sys/mman.h>
#include <sys/simpl_builtin.h>
#include <stdint.h>

extern Block *freelist;
extern size_t block_size;
extern void    *memory_pool;
extern uint32_t bitmap[BITMAP_SIZE / 32];

/*
 * Function to find a free block in the freelist
 * size: size of the memory to be allocated
 * alignment: alignment of the memory to be allocated
 * Returns: pointer to the allocated memory
 */

void *ARCH_SYM(find_free_block)(size_t size, size_t alignment)
{
    if (!memory_pool || size == 0 || size > MEMORY_POOL_SIZE)
        return NULL;

    const size_t units_needed = (size + BLOCK_UNIT_SIZE - 1) / BLOCK_UNIT_SIZE;
    const size_t num_words    = BITMAP_SIZE / 32;
    const uintptr_t pool_base = (uintptr_t)memory_pool;
    const uintptr_t pool_end  = pool_base + MEMORY_POOL_SIZE;

    for (size_t word = 0; word < num_words; ++word)
    {
        if (word == 0) // preserve original: skip first 32 bits entirely
            continue;

        uint32_t free_bits = ~bitmap[word]; // 1s where the bit is free

        while (free_bits)
        {
            const int bit_in_word   = simpl_ctz(free_bits);
            const size_t start_bit  = word * 32u + (unsigned)bit_in_word;
            const uintptr_t addr    = pool_base + start_bit * BLOCK_UNIT_SIZE;

            if (addr + size > pool_end)
                break; // nothing beyond fits

            int enough_space = 1;
            for (size_t k = 0; k < units_needed; ++k)
            {
                const size_t idx = start_bit + k;
                if (idx >= BITMAP_SIZE ||
                    (bitmap[idx / 32] & (1u << (idx & 31))))
                {
                    enough_space = 0;
                    break;
                }
            }

            if (enough_space)
            {
                // Mark the bits as used
                for (size_t k = 0; k < units_needed; ++k)
                {
                    const size_t idx = start_bit + k;
                    bitmap[idx / 32] |= (1u << (idx & 31));
                }

                // Align the returned pointer (same order as your code)
                uintptr_t aligned_addr = simpl_align_up(addr, alignment);
                if (aligned_addr + size > pool_end)
                    return NULL;

                return (void *)aligned_addr;
            }

            // Clear the bit we just checked and continue
            free_bits &= ~(1u << bit_in_word);
        }
    }

    return NULL;
}
