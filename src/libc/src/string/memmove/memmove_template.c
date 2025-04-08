#include <stdint.h>
#include <stdlib.h>
#include <config.h>
#include <simplv.h>

/*
 * this implementation of the memmove function uses AVX2 
 * instructions to move the memory pointed by src to the memory pointed by dest
 * the function loads 32 bytes at a time and moves the memory to the destination
 *
 * Explanation:
 * The function uses AVX2 instructions to move the memory pointed by src to the memory pointed by dest.
 * The function loads 32 bytes at a time and moves the memory to the destination.
 * The function handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
 * The function uses prefetching to improve performance.
*/

void *ARCH_SYM(memmove)(void *dest, const void *src, size_t len) 
{
    if (len == 0 || dest == src)
        return dest;

    uint8_t *cdest = (uint8_t *)dest;
    const uint8_t *csrc = (const uint8_t *)src;

    if (cdest < csrc) 
	{
        size_t num_blocks = len >> 5;
        size_t remaining_bytes = len & 31;

        const uvec *s = (const uvec *)csrc;
        uvec *d = (uvec *)cdest;
		
        for (size_t i = 0; i < num_blocks; ++i)
            v256b_storeu(d++, v256b_loadu(s++));

        uint8_t *byte_dest = (uint8_t *)d;
        const uint8_t *byte_src = (const uint8_t *)s;
        for (size_t i = 0; i < remaining_bytes; ++i) 
            byte_dest[i] = byte_src[i];
    } else {
        size_t num_blocks = len >> 5;
        size_t remaining_bytes = len & 31;

        const uvec *s = (const uvec *)(csrc + len);
        uvec *d = (uvec *)(cdest + len);

        if (remaining_bytes) 
		{
            const uint8_t *byte_src = csrc + len;
            uint8_t *byte_dest = cdest + len;
            for (size_t i = 0; i < remaining_bytes; ++i)
                byte_dest[-(int)(i + 1)] = byte_src[-(int)(i + 1)];
            s = (const uvec *)(csrc + len - remaining_bytes);
            d = (uvec *)(cdest + len - remaining_bytes);
        }

        for (size_t i = 0; i < num_blocks; ++i) 
		{
            d--;
            s--;
            v256b_storeu(d, v256b_loadu(s));
        }
    }

    return dest;
}
