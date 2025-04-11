#ifndef __WARNING_FUNCTION_AVX_H__
# warning "Please include simpl.h instead of directly including function_avx.h"
#endif

#ifndef __FUNCTION_AVX_H__
# define __FUNCTION_AVX_H__

# define __SIMPLV_TYPE_ONLY
# include "../simpl.h"
# undef __SIMPLV_TYPE_ONLY

# ifndef __FUNC_ATTR_AVX
#  define __FUNC_ATTR_AVX                                                                          \
	  __attribute__((__always_inline__, __nodebug__, __target__("avx"), __min_vector_width__(256)))
# endif

# ifndef __FUNC_AVX
#  define __FUNC_AVX(x) __simpl_##x##_avx
# endif

# define __BASIC_FUNC_AVX_256(name, type, sign)                                                    \
	 static inline vec __FUNC_ATTR_AVX __FUNC_AVX(name)(vec __a, vec __b)                           \
	 {                                                                                             \
		 vec                                   result;                                             \
		 result.type.v256 = __a.type.v256 sign __b.type.v256;                                      \
		 return result;                                                                            \
	 }

# define __BASIC_FUNC_AVX_256_ALL_TYPE(name, sign)                                                 \
	 __BASIC_FUNC_AVX_256(v32c_##name, t_char, sign)                                               \
	 __BASIC_FUNC_AVX_256(v32sc_##name, t_schar, sign)                                             \
	 __BASIC_FUNC_AVX_256(v32uc_##name, t_uchar, sign)                                             \
	 __BASIC_FUNC_AVX_256(v16s_##name, t_short, sign)                                              \
	 __BASIC_FUNC_AVX_256(v16us_##name, t_ushort, sign)                                            \
	 __BASIC_FUNC_AVX_256(v8i_##name, t_int, sign)                                                 \
	 __BASIC_FUNC_AVX_256(v8ui_##name, t_uint, sign)                                               \
	 __BASIC_FUNC_AVX_256(v8f_##name, t_float, sign)                                               \
	 __BASIC_FUNC_AVX_256(v4d_##name, t_double, sign)                                              \
	 __BASIC_FUNC_AVX_256(v4ll_##name, t_long_long, sign)                                          \
	 __BASIC_FUNC_AVX_256(v4ull_##name, t_ulong_long, sign)

# define __BASIC_FUNC_AVX_ALL_TYPE(name, sign) __BASIC_FUNC_AVX_256_ALL_TYPE(name, sign)

__BASIC_FUNC_AVX_ALL_TYPE(add, +)
__BASIC_FUNC_AVX_ALL_TYPE(sub, -)
__BASIC_FUNC_AVX_ALL_TYPE(mul, *)
__BASIC_FUNC_AVX_ALL_TYPE(div, /)
__BASIC_FUNC_AVX_ALL_TYPE(cmpeq, ==)
__BASIC_FUNC_AVX_ALL_TYPE(cmpgt, >)
__BASIC_FUNC_AVX_ALL_TYPE(cmplt, <)
__BASIC_FUNC_AVX_ALL_TYPE(cmpge, >=)
__BASIC_FUNC_AVX_ALL_TYPE(cmple, <=)

static inline vec __FUNC_ATTR_AVX __FUNC_AVX(v256b_set_char)(
    char __a, char __b, char __c, char __d, char __e, char __f, char __g, char __h, char __i,
    char __j, char __k, char __l, char __m, char __n, char __o, char __p, char __q, char __r,
    char __s, char __t, char __u, char __v, char __w, char __x, char __y, char __z, char __aa,
    char __bb, char __cc, char __dd, char __ee, char __ff) 
{
	vec result;
	result.t_char.v256 = (__v32c){
		__a, __b, __c, __d, __e, __f, __g, __h, __i, __j,
		__k, __l, __m, __n, __o, __p, __q, __r, __s,  __t,
		__u, __v, __w, __x, __y, __z, __aa, __bb, __cc,
		__dd, __ee, __ff}; 
	return result;
}

static inline vec __FUNC_ATTR_AVX __FUNC_AVX(v32c_blendv)(vec a, vec b, vec mask)
{
	vec r;
	r.t_char.v256 = (__v32c)__builtin_ia32_pblendvb256(
	    (__v32c)a.t_char.v256, (__v32c)b.t_char.v256, (__v32c)mask.t_char.v256);
	return r;
}

static inline vec __FUNC_ATTR_AVX __FUNC_AVX(v256b_set1_char)(char __a)
{
	vec result;
	result.t_char.v256 = (__v32c){__a, __a, __a, __a, __a, __a, __a, __a,
	                              __a, __a, __a, __a, __a, __a, __a, __a,
	                              __a, __a, __a, __a, __a, __a, __a, __a,
	                              __a, __a, __a, __a, __a, __a, __a,  __a};
	return result;
}

static inline int __FUNC_ATTR_AVX __FUNC_AVX(v32c_movemask)(vec __a)
{
	return __builtin_ia32_pmovmskb256((__v32c)__a.t_char.v256);
}

static inline vec __FUNC_ATTR_AVX __FUNC_AVX(v256b_loadu)(const uvec *__a)
{
	struct v256b_loadu {
		__uv4ll result;
	} __attribute__((__packed__, __may_alias__));

	return (*(vec *)&((struct v256b_loadu *)__a)->result);
}

static inline vec __FUNC_ATTR_AVX __FUNC_AVX(v256b_setzero)(void)
{
	vec result;
	result.t_char.v256 = (__v32c){0};
	return result;
}

static inline vec __FUNC_ATTR_AVX __FUNC_AVX(v256b_min)(vec __a, vec __b)
{
	vec result;
	result.t_uint.v256 = __builtin_elementwise_min((__v8ui)__a.t_uint.v256,
	                                               (__v8ui)__b.t_uint.v256);
	return result;
}

static inline void __FUNC_ATTR_AVX __FUNC_AVX(v256b_store)(vec *__a, vec __b)
{
	*__a = __b;
}

static inline void __FUNC_ATTR_AVX __FUNC_AVX(v256b_storeu)(uvec *__a, vec __b)
{
	struct v256b_storeu {
		__uv32c result;
	} __attribute__((__packed__, __may_alias__));

	((struct v256b_storeu *)__a)->result = __b.t_char.v256;
}

# undef __FUNC_ATTR_AVX
# undef __SIMPLV_TYPE_ONLY

#endif /* __FUNCTION_AVX_H__ */
