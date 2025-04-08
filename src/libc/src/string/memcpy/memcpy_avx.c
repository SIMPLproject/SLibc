#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include <config.h>

/*
 *  this implementation of the memcpy function using AVX2 instructions
 *  less instruction, less cache misses, less branch mispredictions
*/

	/*
		* handle the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
		* load 32 bytes from the memory pointed by s and store them in the memory pointed by d.
		* prefetch the next 32 bytes to improve performance.
	*/

/*
		* chunks is the number of 32 bytes chunks in the memory block.
		* remaining_bytes is the number of bytes that are not part of a 32 bytes chunk.
		* The function copies the memory 32 bytes at a time.
		* The function uses prefetching to improve performance.
	*/



void *_memcpy_avx(void *dest, const void *src, size_t len) {
    if (len == 0 || dest == src) {
        return dest;
    }

    uint8_t *cdest = (uint8_t *)dest;
    const uint8_t *csrc = (const uint8_t *)src;

    size_t num_blocks = len >> 5; 
    size_t remaining_bytes = len & 31;

    size_t num_unrolled = num_blocks >> 3;
    size_t remainder_blocks = num_blocks & 7;


	const uvec *s = (const uvec *)csrc;
	uvec *d = (uvec *)cdest;

    for (size_t i = 0; i < num_unrolled; ++i) {
		if (len <= 256)
		{
			_mm_prefetch((const char *)(s + 8), _MM_HINT_T0);
			_mm_prefetch((const char *)(d + 8), _MM_HINT_T0);
		}
		v256b_storeu(d++, v256b_loadu(s++));
        v256b_storeu(d++, v256b_loadu(s++));
        v256b_storeu(d++, v256b_loadu(s++));
        v256b_storeu(d++, v256b_loadu(s++));
        v256b_storeu(d++, v256b_loadu(s++));
        v256b_storeu(d++, v256b_loadu(s++));
		v256b_storeu(d++, v256b_loadu(s++));
        v256b_storeu(d++, v256b_loadu(s++));
	}	
    for (size_t i = 0; i < remainder_blocks; ++i) {
        v256b_storeu(d++, v256b_loadu(s++));
    }

    uint8_t *byte_dest = (uint8_t *)d;
    const uint8_t *byte_src = (const uint8_t *)s;
    for (size_t i = 0; i < remaining_bytes; ++i) {
        byte_dest[i] = byte_src[i];
    }

    return dest;
}

