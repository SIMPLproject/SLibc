#ifndef __WARNING_FUNCTION_VEC128_H__
# warning "Please include simpl.h instead of directly including function_vec256.h"
#endif

#ifndef __FUNCTION_VEC128_H__
# define __FUNCTION_VEC128_H__

# define __SIMPLV_TYPE_ONLY
# include "../simpl.h"
# undef __SIMPLV_TYPE_ONLY

# define __WARNING_FUNCTION_SSE_H__
# include "function_sse.h"

#  define __SIMPLV_FUNC(x) __FUNC_SSE(x)
#  define __SIMPLV_VECTOR_SIZE 128
#  define __SIMPLV_TARGET "sse"

# define __SIMPLV_ATTR                                                                             \
	 __attribute__((__always_inline__, __nodebug__, __target__(__SIMPLV_TARGET),                   \
		              __min_vector_width__(__SIMPLV_VECTOR_SIZE)))

static inline __SIMPLV_ATTR vec128 v16c_add(vec128 __a, vec128 __b)
{	
	return __SIMPLV_FUNC(v16c_add)(__a, __b);
}

static inline __SIMPLV_ATTR vec128 v16c_cmpeq(vec128 __a, vec128 __b)
{
	return __SIMPLV_FUNC(v16c_cmpeq)(__a, __b);
}

static inline __SIMPLV_ATTR vec v256b_set_char(char __a, char __b, char __c, char __d, char __e,
                                               char __f, char __g, char __h, char __i, char __j,
                                               char __k, char __l, char __m, char __n, char __o,
                                               char __p, char __q, char __r, char __s, char __t,
                                               char __u, char __v, char __w, char __x, char __y,
                                               char __z, char __aa, char __bb, char __cc, char __dd,
                                               char __ee, char __ff)
{
	return __SIMPLV_FUNC(v256b_set_char)(__a, __b, __c, __d, __e, __f, __g, __h, __i, __j, __k, __l,
	                                     __m, __n, __o, __p, __q, __r, __s, __t, __u, __v, __w, __x,
	                                     __y, __z, __aa, __bb, __cc, __dd, __ee, __ff);
}

static inline __SIMPLV_ATTR vec v256b_set1_char(char __a)
{
	return __SIMPLV_FUNC(v256b_set1_char)(__a);
}

static inline __SIMPLV_ATTR int v32c_movemask(vec128 __a) { return __SIMPLV_FUNC(v16c_movemask)(__a); }


static inline __SIMPLV_ATTR vec128 v128b_loadu(const uvec128 *__a)
{
	return __SIMPLV_FUNC(v128b_loadu)(__a);
}

static inline __SIMPLV_ATTR vec128 v16c_blendv(vec128 __a, vec128 __b, vec128 __mask)
{
	return __SIMPLV_FUNC(v16c_blendv)(__a, __b, __mask);
}

static inline __SIMPLV_ATTR vec v32c_blendv(vec __a, vec __b, vec __mask)
{
	return __SIMPLV_FUNC(v32c_blendv)(__a, __b, __mask);
}

static inline __SIMPLV_ATTR vec v256b_setzero(void)
{
	return __SIMPLV_FUNC(v256b_setzero)();
}

static inline __SIMPLV_ATTR vec v256b_min(vec __a, vec __b)
{
	return __SIMPLV_FUNC(v256b_min)(__a, __b);
}

static inline __SIMPLV_ATTR void v256b_storeu(uvec *__p, vec __a)
{
	__SIMPLV_FUNC(v256b_storeu)(__p, __a);
}

static inline __SIMPLV_ATTR void v256b_store(vec *__p, vec __a)
{
	__SIMPLV_FUNC(v256b_store)(__p, __a);
}

#endif /* __FUNCTION_VEC128_H__ */
