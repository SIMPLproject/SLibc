#ifndef __SIMPLV_H__
#define __SIMPLV_H__

#include <sys/cdefs.h>
#define __WARNING_TYPE_AVX_H__
#include "multiarch/type_avx.h"
#define __WARNING_TYPE_SSE_H__
#include "multiarch/type_sse.h"

/* Aligned types (default) */

/* Normal type */

typedef __v2d v2d;

typedef __v4f v4f;

typedef __v2ll v2ll;

typedef __v4i v4i;

typedef __v8s v8s;

typedef __v16c v16c;

typedef __v16sc v16sc;

typedef union v4d {
	__v4d v256;
	__v2d v128[2];
} v4d;

typedef union v8f {
	__v8f v256;
	__v4f v128[2];
} v8f;

typedef union v4ll {
	__v4ll v256;
	__v2ll v128[2];
} v4ll;

typedef union v8i {
	__v8i v256;
	__v4i v128[2];
} v8i;

typedef union v16s {
	__v16s v256;
	__v8s  v128[2];
} v16s;

typedef union v32c {
	__v32c v256;
	__v16c v128[2];
} v32c;

typedef union v32sc {
	__v32sc v256;
	__v16sc v128[2];
} v32sc;

/* Unsigned types */

typedef __v2ull v2ull;

typedef __v4ui v4ui;

typedef __v8us v8us;

typedef __v16uc v16uc;

typedef union v4ull {
	__v4ull v256;
	__v2ull v128[2];
} v4ull;

typedef union v8ui {
	__v8ui v256;
	__v4ui v128[2];
} v8ui;

typedef union v16us {
	__v16us v256;
	__v8us  v128[2];
} v16us;

typedef union v32uc {
	__v32uc v256;
	__v16uc v128[2];
} v32uc;

/* Unaligned types */

typedef __uv2d uv2d;

typedef __uv4f uv4f;

typedef __uv2ll uv2ll;

typedef __uv4i uv4i;

typedef __uv8s uv8s;

typedef __uv16c uv16c;

typedef __uv16sc uv16sc;

typedef union uv4d {
	__uv4d uv256;
	__uv2d uv128[2];
} uv4d;

typedef union uv8f {
	__uv8f uv256;
	__uv4f uv128[2];
} uv8f;

typedef union uv4ll {
	__uv4ll uv256;
	__uv2ll uv128[2];
} uv4ll;

typedef union uv8i {
	__uv8i uv256;
	__uv4i uv128[2];
} uv8i;

typedef union uv16s {
	__uv16s uv256;
	__uv8s  uv128[2];
} uv16s;

typedef union uv32c {
	__uv32c uv256;
	__uv16c uv128[2];
} uv32c;

typedef union uv32sc {
	__uv32sc uv256;
	__uv16sc uv128[2];
} uv32sc;

/* Unsigned types */

typedef __uv2ull uv2ull;

typedef __uv4ui uv4ui;

typedef __uv8us uv8us;

typedef __uv16uc uv16uc;

typedef union uv4ull {
	__uv4ull uv256;
	__uv2ull uv128[2];
} uv4ull;

typedef union uv8ui {
	__uv8ui uv256;
	__uv4ui uv128[2];
} uv8ui;

typedef union uv16us {
	__uv16us uv256;
	__uv8us  uv128[2];
} uv16us;

typedef union uv32uc {
	__uv32uc uv256;
	__uv16uc uv128[2];
} uv32uc;

/* VEC definition */

typedef union vec {
	v4d   t_double;
	v4ll  t_long_long;
	v4ull t_ulong_long;

	v8f  t_float;
	v8i  t_int;
	v8ui t_uint;

	v16s  t_short;
	v16us t_ushort;

	v32c  t_char;
	v32sc t_schar;
	v32uc t_uchar;
} vec;

/* VEC unaligned definition */

typedef union uvec {
	uv4d   t_double;
	uv8f   t_float;
	uv4ll  t_long_long;
	uv8i   t_int;
	uv16s  t_short;
	uv32c  t_char;
	uv32sc t_schar;

	uv4ull t_ulong_long;
	uv8ui  t_uint;
	uv16us t_ushort;
	uv32uc t_uchar;
} uvec;

/* VEC definition */

typedef union vec128 {
	v2d   t_double;
	v4f   t_float;
	v2ll  t_long_long;
	v4i   t_int;
	v8s   t_short;
	v16c  t_char;
	v16sc t_schar;

	v2ull t_ulong_long;
	v4ui  t_uint;
	v8us  t_ushort;
	v16uc t_uchar;
} vec128;

/* VEC unaligned definition */

typedef union uvec128 {
	uv2d   t_double;
	uv4f   t_float;
	uv2ll  t_long_long;
	uv4i   t_int;
	uv8s   t_short;
	uv16c  t_char;
	uv16sc t_schar;

	uv2ull t_ulong_long;
	uv4ui  t_uint;
	uv8us  t_ushort;
	uv16uc t_uchar;
} uvec128;

#ifndef __SIMPLV_TYPE_ONLY

// real definition of all funciton
# define __WARNING_FUNCTION_VEC256_H__
# include "multiarch/function_vec256.h"

vec v32c_add(vec __a, vec __b);

vec v32c_cmpeq(vec __a, vec __b);

vec v256b_set_char(char __a, char __b, char __c, char __d, char __e, char __f, char __g, char __h,
                   char __i, char __j, char __k, char __l, char __m, char __n, char __o, char __p,
                   char __q, char __r, char __s, char __t, char __u, char __v, char __w, char __x,
                   char __y, char __z, char __aa, char __bb, char __cc, char __dd, char __ee,
                   char __ff);

vec v256b_set1_char(char __a);

int v32c_movemask(vec __a);

vec v256b_loadu(const uvec *__p);

vec v32c_blendv(vec __a, vec __b, vec __mask);

vec v256b_setzero(void);

vec v256b_min(vec __a, vec __b);

#endif /* __SIMPLV_TYPE_ONLY */

#endif /* __SIMPLV_H__ */
