/*
	* This implementation is based on the assumption that the strings are not equal
* and that n is not 0.
* The function compares the strings 32 bytes at a time using AVX2 instructions.
* It first aligns the pointers to 32 bytes and compares the initial bytes
* until the pointers are aligned.
	* Then it compares the strings 32 bytes at a time using AVX2 instructions.
	* If a difference is found, it returns the difference.
	* If the strings are equal, it returns 0.
	* If the function reaches the end of the strings, it returns 0.
	* The function is optimized for large strings and strings with a length multiple of 32.
*/

#include <simplv.h>
#include <stdint.h>
#include <immintrin.h>
#include <config.h>

int ARCH_SYM(strncmp)(const char *s1, const char *s2, size_t n)
{
    if (__builtin_expect(n == 0, 0) || __builtin_expect(s1 == s2, 0))
        return 0;

    const char *ptr1 = s1;
    const char *ptr2 = s2;
    
    uintptr_t align1 = (uintptr_t)ptr1 & 31;
    uintptr_t align2 = (uintptr_t)ptr2 & 31;
    
    if (align1 != align2)
    {
        while (n && ((uintptr_t)ptr1 & 31) && ((uintptr_t)ptr2 & 31))
        {
            if (*ptr1 != *ptr2)
                return (unsigned char)*ptr1 - (unsigned char)*ptr2;
            ptr1++;
            ptr2++;
            n--;
        }
    }

    size_t chunks = n >> 5;
    while (chunks--)
    {
        vec v1 = v256b_loadu((const uvec *)ptr1);
        vec v2 = v256b_loadu((const uvec *)ptr2);
        
        vec cmp = v32c_cmpeq(v1, v2);
        unsigned mask = (unsigned)v32c_movemask(cmp);
        
        if (mask != 0xFFFFFFFF)
        {
            unsigned diff_pos = (unsigned)__builtin_ctz(~mask);
            return (unsigned char)ptr1[diff_pos] - (unsigned char)ptr2[diff_pos];
        }
        
        ptr1 += 32;
        ptr2 += 32;
    }

    n &= 31;
    while (n--)
    {
        if (*ptr1 != *ptr2)
            return (unsigned char)*ptr1 - (unsigned char)*ptr2;
        ptr1++;
        ptr2++;
    }
    
    return 0;
}
