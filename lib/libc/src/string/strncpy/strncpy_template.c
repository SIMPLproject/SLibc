/*
* an optimized implementation of the strncpy function using AVX2 instructions
* less instruction, less cache misses, less branch mispredictions
* Explanation:
* The function copies the memory 32 bytes at a time using AVX2 instructions.
* The function first aligns the pointers to 32 bytes and copies the initial bytes until the pointers are aligned.
* Then it copies the memory 32 bytes at a time using AVX2 instructions.
* If the function reaches the end of the strings, it pads the remaining bytes with zeros.
* The function is optimized for large strings and strings with a length multiple of 32.
*/

#include <simplv.h>
#include <stdlib.h>
#include <stdint.h>
#include <config.h>

char *ARCH_SYM(strncpy)(char *dst, const char *src, size_t n)
{
    char *origin = dst;
    size_t i = 0;
    const vec zero = v256b_setzero();

    uintptr_t align = (uintptr_t)src & (VEC_SIZE - 1);
    if (align != 0)
    {
        size_t align_size = VEC_SIZE - align;
        if (align_size > n)
            align_size = n;
        for (size_t j = 0; j < align_size; j++, i++)
        {
            dst[i] = src[i];
            if (src[i] == '\0') {
                for (size_t k = i + 1; k < n; k++)
                    dst[k] = '\0';
                return origin;
            }
        }
    }

    while (i + VEC_SIZE <= n)
    {
        vec chunk = v256b_loadu((const uvec *)(src + i));
        vec cmp = v32c_cmpeq(chunk, zero);
        int mask = v32c_movemask(cmp);

        if (mask != 0)
        {
            int pos = __builtin_ctz(mask);
            for (int j = 0; j <= pos; j++)
                dst[i + j] = src[i + j];
            for (size_t j = i + pos + 1; j < n; j++)
                dst[j] = '\0';
            return origin;
        }

		v256b_storeu((uvec *)(dst + i), chunk); 
        i += VEC_SIZE;
    }

    if (i < n)
    {
        size_t remaining = n - i;
        char tmp[32] = {0};
        for (size_t j = 0; j < remaining; j++)
            tmp[j] = src[i + j];

        vec chunk = v256b_loadu((const uvec *)tmp);
        vec cmp = v32c_cmpeq(chunk, zero);
        int mask = v32c_movemask(cmp);

        if (mask != 0)
        {
            int pos = __builtin_ctz(mask);
            for (int j = 0; j <= pos && (i + j) < n; j++)
                dst[i + j] = tmp[j];
            for (size_t j = i + pos + 1; j < n; j++)
                dst[j] = '\0';
        }
        else
        {
            for (size_t j = 0; j < remaining; j++)
                dst[i + j] = tmp[j];
        }
    }

    return origin;
}
