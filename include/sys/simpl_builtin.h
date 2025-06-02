#ifndef __SIMPL_BUILTIN_H__
#define __SIMPL_BUILTIN_H__

#include <bits/simpl_builtin_arch.h>

#if defined(CTZ) && __has_builtin(CTZ)
#    include <string.h>
#    define simpl_ctz(x) CTZ(x)
#else
#    define simpl_ctz(x) ffs(x)
#endif

#if defined(ALIGN_UP)
#    define simpl_align_up(x, a) ALIGN_UP(x, a)
#else
#    define simpl_align_up(x, a) (((x) + (a) - 1) & ~((a) - 1))
#endif

#if defined(__GNUC__) || defined(__clang__)
#    define simpl_assume_aligned(p, a) __builtin_assume_aligned(p, a)
#else
#    define simpl_assume_aligned(p, a) (p)
#endif

#if defined(__GNUC__) || defined(__clang__)
#    define simpl_expect(x, expected) __builtin_expect(x, expected)
#else
#    define simpl_expect(x, expected) ((x) == (expected))
#endif

#endif // __SIMPL_BUILTIN_H__
