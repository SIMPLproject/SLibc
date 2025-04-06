
/* check if the vector v contains a zero byte */
/* return 0 if no zero byte is found, otherwise return a non-zero value */

/*
** trying to benchmark Glibc.... but skill issue atm

* using _mm256_setzero_si256() to create a vector of 32 zero bytes bc assingning a 0 is to lower
(yes I know it's a bit overkill)
* using _mm256_loadu_si256() to load 32 bytes from the memory pointed by ptr in asm :
*                      vpcmpeqb ymm1, ymm0, ymmword ptr [rsi + rcx + 32]

* using has_zero_byte() to check if the vector v contains a zero byte
__builtin_ctz() is a builtin function that returns the number of trailing 0-bits
*/

#include <config.h>
#include <immintrin.h>
#include <stdlib.h>


size_t _strlen_avx(const char *str)
{
    const char *original_ptr = str;
    vec ymm_zero = v256b_setzero(); 

    uintptr_t misalignment = (uintptr_t)str & 31;
    if (misalignment != 0)
    {
        size_t  offset = 32 - misalignment;
        vec ymm_data = v256b_loadu((const uvec *)str);
        vec cmp_result = v32c_cmpeq(ymm_zero, ymm_data);
        int32_t mask = v32c_movemask(cmp_result);

        mask >>= misalignment;

        if (mask != 0)
        {
            int32_t index = __builtin_ctz(mask);
            return (size_t)(str + index - original_ptr);
        }

        str += offset;
    }

    while (1)
    {
        _mm_prefetch(str + 32, _MM_HINT_T0);
        vec ymm_data = v256b_loadu((const uvec *)str);
        vec cmp_result = v32c_cmpeq(ymm_zero, ymm_data);
        int32_t mask = v32c_movemask(cmp_result);

        if (mask != 0)
        {
            int32_t index = __builtin_ctz(mask);
            return (size_t)(str + index - original_ptr);
        }

        str += 32;
    }
    return 0;
}
