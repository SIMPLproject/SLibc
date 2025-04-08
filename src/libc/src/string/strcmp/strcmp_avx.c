#include "SIMPLV/includes/simpl.h"
#include <stdint.h>
#include <config.h>
#include <immintrin.h>

#define VEC_SIZE 32


int _strcmp_avx(const char *s1, const char *s2) 
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
