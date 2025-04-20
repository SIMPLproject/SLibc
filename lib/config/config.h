#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "func_ifunc_selector.h"
#include <sys/cdefs.h>

#if defined(__AVX__) || defined(__AVX2__)
#    define HAS_AVX
#endif

#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__) || defined(__SSSE3__) ||            \
    defined(__SSE4_1__) || defined(__SSE4_2__)
#    define HAS_SSE
#endif

#if defined(ARCHIVE) || defined(NATIVE)
#    define ARCH_SYM(x) _##x
#elif defined(HAS_AVX)
#    define ARCH_SYM(x) _##x##_avx
#elif defined(HAS_SSE)
#    define ARCH_SYM(x) _##x##_sse
#else
#    define ARCH_SYM(x) _##x##_generic
#endif

/* to be remove from there this as noting to do there */
#define AVX2_ALIGNMENT 32
#define AVX2_SIZE 32
#define BLOCK_SIZE 4096
#define CHAR_PER_VEC (AVX2_SIZE / sizeof(char))
#define VEC_SIZE 32

#endif //__CONFIG_H__
