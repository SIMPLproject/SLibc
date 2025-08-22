/*
	* this implementation of the memset function uses AVX2 
*	* instructions to set the memory pointed by b to the value c 
*	* the function loads 32 bytes at a time and sets the memory to the value c
*
*	* Explanation:
*	* The function uses AVX2 instructions to set the memory pointed by b to the value c.
*	* The function loads 32 bytes at a time and sets the memory to the value c.
*	* The function handles the initial bytes separately if the pointer is not aligned on a 32 bytes boundary.
*	* The function uses prefetching to improve performance.
*/

#include <stdint.h>
#include <simplv.h>
#include <config.h>


#define REP_STOSB_THRESHOLD 2048
#define UNROLL_SIZE 96
#define VEC_SIZE 32

void *ARCH_SYM(memset)(void* dest, int c, size_t n) {
    unsigned char* d = (unsigned char*)dest;
    uint8_t value = (uint8_t)c;

    if (n < VEC_SIZE) {
        for (size_t i = 0; i < n; i++) {
            d[i] = value;
        }
        return dest;
    }

    if (n <= 2 * VEC_SIZE) {
        for (size_t i = 0; i < n; i++) {
            d[i] = value;
        }
        return dest;
    }

	// to implement outside of this function
	// no asm inside src this need to be in sysdeps
    // if (n > REP_STOSB_THRESHOLD) {
    //     __asm__ volatile (
    //         "rep stosb"
    //         : "+D" (d), "+c" (n)
    //         : "a" (value)
    //         : "memory"
    //     );
    // } else {
	vec vec = v256b_set1_char(value);
	size_t unroll_count = n / UNROLL_SIZE;
	size_t remainder = n % UNROLL_SIZE;
	// // _mm_prefetch((const char*)d + UNROLL_SIZE, _MM_HINT_T0);
	for (size_t i = 0; i < unroll_count; i++) {
		v256b_storeu((uvec*)d, vec);
		v256b_storeu((uvec*)(d + 32), vec);
		v256b_storeu((uvec*)(d + 64), vec);
		d += UNROLL_SIZE;
	}
	for (size_t i = 0; i < remainder; i++) {
		d[i] = value;
	}
    // }
    return dest;
}

