#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>

#define VEC_SIZE 16

size_t _strlen_sse(const char *s)
{
	if (__builtin_expect(s == NULL, 0))
		return 0;
	const char		*ptr = s;
	const __m256i	zero = _mm256_setzero_si256();
	size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1);

	if (offset != 0) 
	{
		size_t align_size = VEC_SIZE - offset;
		__m256i data = _mm256_loadu_si256((const __m256i *)ptr);
		__m256i cmp = _mm256_cmpeq_epi8(data, zero);
        int mask = _mm256_movemask_epi8(cmp);
        if (mask != 0)
        {
            return (size_t)__builtin_ctz(mask);
        }
        ptr += align_size;
    }

    while (1) 
    {
        __m256i data = _mm256_loadu_si256((const __m256i *)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero);
        int mask = _mm256_movemask_epi8(cmp);
        if (mask != 0)
        {
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += VEC_SIZE;
    }

    return 0;
}

#define SIMPLV_USE_SSE
#include "includes/simpl.h"

size_t _strlen_vec(const char *s)  
{	
	if (__builtin_expect(s == NULL, 0))
		return 0;
	

    const char		*ptr = s;
    vec				zero = v256b_set1_char(0);
    size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1);
    
	if (offset != 0) 
    {
        size_t align_size = VEC_SIZE - offset;
        vec data = v256b_loadu((const uvec *)ptr);
        vec cmp = v32c_cmpeq(data, zero);
        int mask = v32c_movemask(cmp);
        if (mask != 0)
        {
            return (size_t)__builtin_ctz(mask);
        }
        ptr += align_size;
    }
    while (1) 
    {
        vec data = v256b_loadu((const uvec *)ptr);
        vec cmp = v32c_cmpeq(data, zero);
        int mask = v32c_movemask(cmp);
        if (mask != 0)
        {
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += VEC_SIZE;
    }

    return 0;
}


#include <immintrin.h>
#include <stdint.h>

int _strncmp_avx(const char *s1, const char *s2, size_t n)
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
        __m256i v1 = _mm256_loadu_si256((const __m256i *)ptr1);
        __m256i v2 = _mm256_loadu_si256((const __m256i *)ptr2);
        
        __m256i cmp = _mm256_cmpeq_epi8(v1, v2);
        unsigned mask = (unsigned)_mm256_movemask_epi8(cmp);
        
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

int strcmp_avx(const char *s1, const char *s2) 
{
	if (__builtin_expect(s1 == s2, 1))
		return 0;

	size_t i = 0;
	const vec zero = v256b_set1_char(0);

	while (1) 
	{
		vec v1 = v256b_loadu((const uvec *)(s1 + i));
		vec v2 = v256b_loadu((const uvec *)(s2 + i));

		vec cmp_eq = v32c_cmpeq(v1, v2);

		vec neq_mask = v32c_cmpeq(cmp_eq, zero);
		uint32_t diff_mask = v32c_movemask(neq_mask);

		vec iszero1 = v32c_cmpeq(v1, zero);
		vec iszero2 = v32c_cmpeq(v2, zero);
		vec anyzero = v256b_min(iszero1, iszero2);  
		uint32_t zero_mask = v32c_movemask(anyzero);

		if (diff_mask != 0) 
		{
			uint32_t index = __builtin_ctz(diff_mask);

			unsigned char c1 = (unsigned char)s1[i + index];
			unsigned char c2 = (unsigned char)s2[i + index];
			return (int)c1 - (int)c2;
		}

		if (zero_mask != 0) 
			return 0;

		i += VEC_SIZE;
	}
}
int _strcmp(const char *s1, const char *s2, size_t n) {
	if (__builtin_expect(s1 == s2, 1))
		return 0;

	size_t i = 0;
	while (i < n) {
		if (s1[i] != s2[i])
			return (int)(unsigned char)s1[i] - (int)(unsigned char)s2[i];
		i++;
	}

	return 0;
}

char *_strncpy_avx(char *dst, const char *src, size_t n)
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

int main(void)
{
	size_t iterations = 10;
    struct timespec start, end;
    double cpu_time_used;
	char *str = malloc(1024 * 1024 * 1024);
	memset(str, 1, 1024 * 1024 * 1024);
	char *str3 = "hello world djsaklsdal\0skdalskjdlaskjdlask";
	char *str2 = "hello";

	int size;
	int size_real;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		 size =_strlen_vec(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("vec: %f seconds\n", cpu_time_used);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		 size_real =_strlen_sse(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("sse: %f seconds\n", cpu_time_used);
	printf("%d\n", size);
	printf("%d\n", size_real);

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iterations; i++) {
		 size_real =_strncmp_avx(str3, str2, strlen(str2) + 1);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("vec: %f seconds\n", cpu_time_used);
	printf("%d\n", size_real);
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iterations; i++) {
		 size_real = strncmp(str3, str2, strlen(str2) + 1);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("real: %f seconds\n", cpu_time_used);
	printf("%d\n", size_real);

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iterations; i++) {
		 size_real =_strcmp(str3, str2, strlen(str2) + 1);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("normal: %f seconds\n", cpu_time_used);
	printf("%d\n", size_real);


	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iterations; i++) {
		 size_real = strcmp_avx(str3, str2);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("avx: %f seconds\n", cpu_time_used);
	printf("%d\n", size_real);
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (size_t i = 0; i < iterations; i++) {
		 size_real = strcmp(str3, str2);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
	printf("real: %f seconds\n", cpu_time_used);
	printf("%d\n", size_real);
	free(str);
}
