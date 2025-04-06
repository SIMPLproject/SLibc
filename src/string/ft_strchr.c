/*
 * This implementation is based on the assumption that the string is not empty.
 * The function compares the string 32 bytes at a time using AVX2 instructions.
 * It first aligns the pointer to 32 bytes and compares the initial bytes
 * until the pointer is aligned.
 * Then it compares the string 32 bytes at a time using AVX2 instructions.
 * If the character is found, it returns a pointer to the character.
 * If the function reaches the end of the string, it returns NULL.
 * The function is optimized for large strings and strings with a length multiple of 32.
*/

#include "SIMPLV/includes/simpl.h"
#include <stdint.h>
#include <immintrin.h>
#include <stdlib.h>
#include <config.h>



char *_strchr_avx(const char *p, int ch)
{
    if (__builtin_expect(p == NULL, 0))
        return NULL;

    const unsigned char *ptr = (const unsigned char *)p;
    const unsigned char c = (unsigned char)ch;
    const size_t offset = (uintptr_t)ptr & (VEC_SIZE - 1);

    if (__builtin_expect(offset != 0, 0))
    {
        const size_t align_size = VEC_SIZE - offset;
        for (size_t i = 0; i < align_size; i++)
        {
            unsigned char current = ptr[i];
            if (__builtin_expect(current == c, 1))
                return (char *)(ptr + i);
            if (__builtin_expect(current == '\0', 0))
                return NULL;
        }
        ptr += align_size;
    }

    const vec needle = v256b_set1_char(c);
    const vec zero   = v256b_setzero();
    unsigned char_mask, null_mask;

    while (1)
    {
        vec data      = v256b_loadu((const uvec *)ptr);
        vec cmp_char  = v32c_cmpeq(data, needle);
        char_mask     = (unsigned)v32c_movemask(cmp_char);
        if (char_mask != 0)
            return (char *)(ptr + __builtin_ctz(char_mask));

        vec cmp_zero  = v32c_cmpeq(data, zero);
        null_mask     = (unsigned)v32c_movemask(cmp_zero);
        if (__builtin_expect(null_mask != 0, 0))
            return NULL;

        ptr += VEC_SIZE;
        _mm_prefetch((const char *)(ptr + VEC_SIZE), _MM_HINT_T0);
    }
}

