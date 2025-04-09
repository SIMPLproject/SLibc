#ifndef __WARNING_TYPE_SSE_H__
# warning "Please include simpl.h instead of directly including type_sse.h"
#endif /* __WARNING_TYPE_SSE_H__ */

#ifndef __TYPE_SSE_H__
# define __TYPE_SSE_H__

/* Determine architecture width */
# if defined __x86_64__ && !defined __ILP32__
#  define __ARCH_WIDTH 64
# else
#  define __ARCH_WIDTH 32
# endif

/* Define 64-bit integer types based on architecture */
# if __ARCH_WIDTH == 64
typedef unsigned long int __sp_uint64_t;
typedef signed long int   __sp_int64_t;
# else
__extension__ typedef unsigned long long int __sp_uint64_t;
__extension__ typedef signed long long int   __sp_int64_t;
# endif

/* Aligned types (default) */

/* Normal type */
typedef double       __v2d __attribute__((__vector_size__(16), aligned(16)));
typedef float        __v4f __attribute__((__vector_size__(16), aligned(16)));
typedef __sp_int64_t __v2ll __attribute__((__vector_size__(16), aligned(16)));
typedef int          __v4i __attribute__((__vector_size__(16), aligned(16)));
typedef short        __v8s __attribute__((__vector_size__(16), aligned(16)));
typedef char         __v16c __attribute__((__vector_size__(16), aligned(16)));
typedef signed char  __v16sc __attribute__((__vector_size__(16), aligned(16)));

/* Unsigned types */
typedef __sp_uint64_t  __v2ull __attribute__((__vector_size__(16), aligned(16)));
typedef unsigned int   __v4ui __attribute__((__vector_size__(16), aligned(16)));
typedef unsigned short __v8us __attribute__((__vector_size__(16), aligned(16)));
typedef unsigned char  __v16uc __attribute__((__vector_size__(16), aligned(16)));

/* Unaligned types */

/* Normal type */
typedef double       __uv2d __attribute__((__vector_size__(16), aligned(1)));
typedef float        __uv4f __attribute__((__vector_size__(16), aligned(1)));
typedef __sp_int64_t __uv2ll __attribute__((__vector_size__(16), aligned(1)));
typedef int          __uv4i __attribute__((__vector_size__(16), aligned(1)));
typedef short        __uv8s __attribute__((__vector_size__(16), aligned(1)));
typedef char         __uv16c __attribute__((__vector_size__(16), aligned(1)));
typedef signed char  __uv16sc __attribute__((__vector_size__(16), aligned(1)));

/* Unsigned types */
typedef __sp_uint64_t  __uv2ull __attribute__((__vector_size__(16), aligned(1)));
typedef unsigned int   __uv4ui __attribute__((__vector_size__(16), aligned(1)));
typedef unsigned short __uv8us __attribute__((__vector_size__(16), aligned(1)));
typedef unsigned char  __uv16uc __attribute__((__vector_size__(16), aligned(1)));

#endif /* __TYPE_SSE_H__ */
