#ifndef __WARNING_FUNCTION_SSE_H__
# warning "Please include simpl.h instead of directly including function_sse.h"
#endif

#ifndef __FUNCTION_SSE_H__
# define __FUNCTION_SSE_H__

# define __SIMPLV_TYPE_ONLY
# include "../simpl.h"
# undef __SIMPLV_TYPE_ONLY

# ifndef __FUNC_ATTR_SSE
#  define __FUNC_ATTR_SSE                                                                          \
	  __attribute__((__always_inline__, __nodebug__, __target__("sse"), __min_vector_width__(128)))
# endif

# ifndef __FUNC_SSE
#  define __FUNC_SSE(x) __simpl_##x##_sse
# endif

# define __BASIC_FUNC_SSE_128(name, type, sign)                                                    \
	 static inline vec128 __FUNC_ATTR_SSE __FUNC_SSE(name)(vec128 __a, vec128 __b)                 \
	 {                                                                                             \
		 vec128                      result;                                                       \
		 result.type = __a.type sign __b.type;                                                     \
		 return result;                                                                            \
	 }

# define __BASIC_FUNC_SSE_256(name, type, sign)                                                    \
	 static inline vec __FUNC_ATTR_SSE __FUNC_SSE(name)(vec __a, vec __b)                          \
	 {                                                                                             \
		 vec                                         result;                                       \
		 result.type.v128[0] = __a.type.v128[0] sign __b.type.v128[0];                             \
		 result.type.v128[1] = __a.type.v128[1] sign __b.type.v128[1];                             \
		 return result;                                                                            \
	 }

# define __BASIC_FUNC_SSE_128_ALL_TYPE(name, sign)                                                 \
	 __BASIC_FUNC_SSE_128(v16c_##name, t_char, sign)                                               \
	 __BASIC_FUNC_SSE_128(v16sc_##name, t_schar, sign)                                             \
	 __BASIC_FUNC_SSE_128(v16uc_##name, t_uchar, sign)                                             \
	 __BASIC_FUNC_SSE_128(v8s_##name, t_short, sign)                                               \
	 __BASIC_FUNC_SSE_128(v8us_##name, t_ushort, sign)                                             \
	 __BASIC_FUNC_SSE_128(v4i_##name, t_int, sign)                                                 \
	 __BASIC_FUNC_SSE_128(v4ui_##name, t_uint, sign)                                               \
	 __BASIC_FUNC_SSE_128(v4f_##name, t_float, sign)                                               \
	 __BASIC_FUNC_SSE_128(v2d_##name, t_double, sign)                                              \
	 __BASIC_FUNC_SSE_128(v2ll_##name, t_long_long, sign)                                          \
	 __BASIC_FUNC_SSE_128(v2ull_##name, t_ulong_long, sign)

# define __BASIC_FUNC_SSE_256_ALL_TYPE(name, sign)                                                 \
	 __BASIC_FUNC_SSE_256(v32c_##name, t_char, sign)                                               \
	 __BASIC_FUNC_SSE_256(v32sc_##name, t_schar, sign)                                             \
	 __BASIC_FUNC_SSE_256(v32uc_##name, t_uchar, sign)                                             \
	 __BASIC_FUNC_SSE_256(v16s_##name, t_short, sign)                                              \
	 __BASIC_FUNC_SSE_256(v16us_##name, t_ushort, sign)                                            \
	 __BASIC_FUNC_SSE_256(v8i_##name, t_int, sign)                                                 \
	 __BASIC_FUNC_SSE_256(v8ui_##name, t_uint, sign)                                               \
	 __BASIC_FUNC_SSE_256(v8f_##name, t_float, sign)                                               \
	 __BASIC_FUNC_SSE_256(v4d_##name, t_double, sign)                                              \
	 __BASIC_FUNC_SSE_256(v4ll_##name, t_long_long, sign)                                          \
	 __BASIC_FUNC_SSE_256(v4ull_##name, t_ulong_long, sign)

# define __BASIC_FUNC_SSE_ALL_TYPE(name, sign)                                                     \
	 __BASIC_FUNC_SSE_128_ALL_TYPE(name, sign)                                                     \
	 __BASIC_FUNC_SSE_256_ALL_TYPE(name, sign)

__BASIC_FUNC_SSE_ALL_TYPE(add, +)
__BASIC_FUNC_SSE_ALL_TYPE(sub, -)
__BASIC_FUNC_SSE_ALL_TYPE(mul, *)
__BASIC_FUNC_SSE_ALL_TYPE(div, /)
__BASIC_FUNC_SSE_ALL_TYPE(cmpeq, ==)
__BASIC_FUNC_SSE_ALL_TYPE(cmpgt, >)
__BASIC_FUNC_SSE_ALL_TYPE(cmplt, <)
__BASIC_FUNC_SSE_ALL_TYPE(cmpge, >=)
__BASIC_FUNC_SSE_ALL_TYPE(cmple, <=)

static inline vec __FUNC_ATTR_SSE __FUNC_SSE(v256b_set_char)(
    char __a, char __b, char __c, char __d, char __e, char __f, char __g, char __h, char __i,
    char __j, char __k, char __l, char __m, char __n, char __o, char __p, char __q, char __r,
    char __s, char __t, char __u, char __v, char __w, char __x, char __y, char __z, char __aa,
    char __bb, char __cc, char __dd, char __ee, char __ff)
{
	vec result;
	result.t_char.v128[0] =
	    (__v16c){__a, __b, __c, __d, __e, __f, __g, __h, __i, __j, __k, __l, __m, __n, __o, __p};

	result.t_char.v128[1] = (__v16c){__q, __r, __s,  __t,  __u,  __v,  __w,  __x,
	                                 __y, __z, __aa, __bb, __cc, __dd, __ee, __ff};
	return result;
}

static inline vec128 __FUNC_ATTR_SSE __FUNC_SSE(v16c_blendv)(vec128 a, vec128 b, vec128 mask)
{
	vec128 r;
	r.t_char = (__v16c)__builtin_ia32_pblendvb128(
	    (__v16c)a.t_char, (__v16c)b.t_char, (__v16c)mask.t_char);
	return r;
}

static inline vec __FUNC_ATTR_SSE __FUNC_SSE(v32c_blendv)(vec a, vec b, vec mask)
{
	vec r;
	r.t_char.v128[0] = (__v16c)__builtin_ia32_pblendvb128(
	    (__v16c)a.t_char.v128[0], (__v16c)b.t_char.v128[0], (__v16c)mask.t_char.v128[0]);
	r.t_char.v128[1] = (__v16c)__builtin_ia32_pblendvb128(
	    (__v16c)a.t_char.v128[1], (__v16c)b.t_char.v128[1], (__v16c)mask.t_char.v128[1]);
	return r;
}

static inline vec128 __FUNC_ATTR_SSE __FUNC_SSE(v128b_set_char)(char __a, char __b, char __c,
                                                                char __d, char __e, char __f,
                                                                char __g, char __h)
{
	vec128 result;
	result.t_char =
	    (__v16c){__a, __b, __c, __d, __e, __f, __g, __h, __a, __b, __c, __d, __e, __f, __g, __h};
	return result;
}

static inline vec __FUNC_ATTR_SSE __FUNC_SSE(v256b_set1_char)(char __a)
{
	vec result;
	result.t_char.v128[0] =
	    (__v16c){__a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a};
	result.t_char.v128[1] =
	    (__v16c){__a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a, __a};
	return result;
}



static inline int __FUNC_ATTR_SSE __FUNC_SSE(v16c_movemask)(vec128 __a)
{
	return __builtin_ia32_pmovmskb128(__a.t_char);
}

static inline int __FUNC_ATTR_SSE __FUNC_SSE(v32c_movemask)(vec __a)
{
	return __builtin_ia32_pmovmskb128(__a.t_char.v128[0]) |
	       (__builtin_ia32_pmovmskb128(__a.t_char.v128[1]) << 16);
}

static inline vec128 __FUNC_ATTR_SSE __FUNC_SSE(v128b_loadu)(const uvec128 *__a)
{
	struct v128b_loadu {
		__uv2ll result;
	} __attribute__((__packed__, __may_alias__));

	return (*(vec128 *)&((const struct v128b_loadu *)__a)->result);
}

static inline vec __FUNC_ATTR_SSE __FUNC_SSE(v256b_loadu)(const uvec *__a)
{
	struct v256b_loadu {
		__uv4ll result;
	} __attribute__((__packed__, __may_alias__));

	return (*(vec *)&((const struct v256b_loadu *)__a)->result);
}

static inline vec128 __FUNC_ATTR_SSE __FUNC_SSE(v128b_setzero)(void)
{
	vec128 result;
	result.t_char = (__v16c){0LL, 0LL};	
	return result;
}

static inline vec __FUNC_ATTR_SSE __FUNC_SSE(v256b_setzero)(void)
{
	vec result;
	result.t_char.v128[0] = (__v16c){0LL, 0LL};
	result.t_char.v128[1] = (__v16c){0LL, 0LL};
	return result;
}

static inline vec128 __FUNC_ATTR_SSE __FUNC_SSE(v16c_min)(vec128 __a, vec128 __b)
{
	vec128 result;
	result.t_uint = (__v4ui)__builtin_elementwise_min(
	    (__v4ui)__a.t_uint, (__v4ui)__b.t_uint);
	return result;
}

static inline vec __FUNC_ATTR_SSE __FUNC_SSE(v256b_min)(vec __a, vec __b)
{
	vec result;
	result.t_uint.v128[0] = (__v4ui)__builtin_elementwise_min(
	    (__v4ui)__a.t_uint.v128[0], (__v4ui)__b.t_uint.v128[0]);
	result.t_uint.v128[1] = (__v4ui)__builtin_elementwise_min(
	    (__v4ui)__a.t_uint.v128[1], (__v4ui)__b.t_uint.v128[1]);
	return result;
}

static inline void __FUNC_ATTR_SSE __FUNC_SSE(v256b_store)(vec *__a, vec __b)
{
	__v16c *dst = (__v16c *)__a;
	dst[0] = __b.t_char.v128[0];
	dst[1] = __b.t_char.v128[1];
}


static inline void __FUNC_ATTR_SSE __FUNC_SSE(v256b_storeu)(uvec *__a, vec __b)
{
	struct v256b_storeu_split {
		__v16c low;
		__v16c high;
	} __attribute__((__packed__, __may_alias__));

	struct v256b_storeu_split *dst = (struct v256b_storeu_split *)__a;
	dst->low = __b.t_char.v128[0];
	dst->high = __b.t_char.v128[1];
}



# undef __FUNC_ATTR_SSE
# undef __SIMPLV_TYPE_ONLY

#endif /* __FUNCTION_SSE_H__ */
