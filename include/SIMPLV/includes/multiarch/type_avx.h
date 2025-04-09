#ifndef __WARNING_TYPE_AVX_H__
# warning "Please include simpl.h instead of directly including type_avx.h"
#endif /* __WARNING_TYPE_AVX_H__ */

#ifndef __TYPE_AVX_H__
# define __TYPE_AVX_H__

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
typedef double       __v4d __attribute__((__vector_size__(32), aligned(32)));
typedef float        __v8f __attribute__((__vector_size__(32), aligned(32)));
typedef __sp_int64_t __v4ll __attribute__((__vector_size__(32), aligned(32)));
typedef int          __v8i __attribute__((__vector_size__(32), aligned(32)));
typedef short        __v16s __attribute__((__vector_size__(32), aligned(32)));
typedef char         __v32c __attribute__((__vector_size__(32), aligned(32)));
typedef signed char  __v32sc __attribute__((__vector_size__(32), aligned(32)));

/* Unsigned types */
typedef __sp_uint64_t  __v4ull __attribute__((__vector_size__(32), aligned(32)));
typedef unsigned int   __v8ui __attribute__((__vector_size__(32), aligned(32)));
typedef unsigned short __v16us __attribute__((__vector_size__(32), aligned(32)));
typedef unsigned char  __v32uc __attribute__((__vector_size__(32), aligned(32)));

/* Unaligned types */

/* Normal type */
typedef double       __uv4d __attribute__((__vector_size__(32), aligned(1)));
typedef float        __uv8f __attribute__((__vector_size__(32), aligned(1)));
typedef __sp_int64_t __uv4ll __attribute__((__vector_size__(32), aligned(1)));
typedef int          __uv8i __attribute__((__vector_size__(32), aligned(1)));
typedef short        __uv16s __attribute__((__vector_size__(32), aligned(1)));
typedef char         __uv32c __attribute__((__vector_size__(32), aligned(1)));
typedef signed char  __uv32sc __attribute__((__vector_size__(32), aligned(1)));

/* Unsigned types */
typedef __sp_uint64_t  __uv4ull __attribute__((__vector_size__(32), aligned(1)));
typedef unsigned int   __uv8ui __attribute__((__vector_size__(32), aligned(1)));
typedef unsigned short __uv16us __attribute__((__vector_size__(32), aligned(1)));
typedef unsigned char  __uv32uc __attribute__((__vector_size__(32), aligned(1)));

#endif /* __TYPE_AVX_H__ */
