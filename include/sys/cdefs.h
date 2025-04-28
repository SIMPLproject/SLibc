#ifndef __CDEFS_H__
#define __CDEFS_H__

/*
 * ─── C STANDARD VERSION ────────────────────────────────────────────────────────
 * Require at least C99.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199901L)
#  error "cdefs.h requires a C compiler with C99 support or later"
#endif

/*
 * ─── COMPILER CHECKS ───────────────────────────────────────────────────────────
 */
#if defined(__clang__)
   /* Clang 3.5+ */
#  if (__clang_major__ < 3) || (__clang_major__ == 3 && __clang_minor__ < 5)
#    error "cdefs.h requires Clang 3.5 or later"
#  endif

#elif defined(__GNUC__)
   /* GCC 5+ */
#  if (__GNUC__ < 5)
#    error "cdefs.h requires GCC 5.0 or later"
#  endif

#elif defined(_MSC_VER)
   /* MSVC 2015+ (_MSC_VER 1900 means VS2015) */
#  if (_MSC_VER < 1900)
#    error "cdefs.h requires MSVC 2015 (Visual Studio 2015) or later"
#  endif

#else
#  error "cdefs.h: unsupported compiler"
#endif

/*
 * ─── EXTRA SECURITY HARDENING ──────────────────────────────────────────────────
 * Turn on _FORTIFY_SOURCE (buffer‐overflow hardening) if available and not already
 * defined, for maximum lightweight protection under GCC/Clang.
 */
#if (defined(__GNUC__) || defined(__clang__)) && !defined(_FORTIFY_SOURCE)
#  define _FORTIFY_SOURCE 2
#endif

/*
 * ─── STRINGIFY HELPERS ─────────────────────────────────────────────────────────
 */
#define __STRINGIFY(x) #x
#define STRINGIFY(x)   __STRINGIFY(x)

/*
 * ─── COMPILER‐SPECIFIC ATTRIBUTES ──────────────────────────────────────────────
 */
#if defined(__clang__) || defined(__GNUC__)
#  define _ALIGN(N)        __attribute__((aligned(N)))
#  define __Inline         __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#  define __Inline         __forceinline
#  define _ALIGN(N)
#else
#  define __Inline         inline
#  define _ALIGN(N)
#endif

/*
 * ─── NON‐NULL ATTRIBUTE ────────────────────────────────────────────────────────
 */
#if defined(__GNUC__) || defined(__clang__)
#  undef __nonnull
#  define __nonnull(...)   __attribute__((__nonnull__(__VA_ARGS__)))
#else
#  define __nonnull(...)
#endif

/*
 * ─── PURE ATTRIBUTE ────────────────────────────────────────────────────────────
 */
#if defined(__GNUC__) || defined(__clang__)
#  undef __attribute_pure__
#  define __attribute_pure__ __attribute__((__pure__))
#else
#  define __attribute_pure__
#endif

/*
 * ─── UNUSED / HIDDEN / NORETURN ────────────────────────────────────────────────
 */
#if defined(__linux__)
#  define __unused         __attribute__((unused))
#  define __hidden         __attribute__((visibility("hidden")))
#  define __no_return      __attribute__((noreturn))
#else
#  define __unused
#  define __hidden
#  define __no_return
#endif

/*
 * ─── WEAK & STRONG ALIASES ─────────────────────────────────────────────────────
 */
#if defined(__APPLE__)
#  define simpl_weak_alias(func, func_source)                         \
     __typeof__(func_source) __attribute__((weak)) *func = &func_source;
#elif defined(__GNUC__) || defined(__clang__)
#  define simpl_weak_alias(func, func_source)                         \
     extern __typeof__(func_source) func                            \
       __attribute__((weak, alias(STRINGIFY(func_source))));
#else
#  define simpl_weak_alias(name, func)                                \
     _Pragma("GCC error \"Weak alias is not supported on this compiler\"")
#endif

#if defined(__linux__)
#  define simpl_strong_alias(func, func_source)                       \
     extern __typeof__(func_source) func                             \
       __attribute__((alias(STRINGIFY(func_source))));
#else
#  define simpl_strong_alias(x, x)
#endif

#undef __attribute_copy__
#if defined(__linux__)
# define __attribute_copy__(x) __attribute__((__copy__(x)))
#else
# define __attribute_copy__(x)
#endif

#endif /* __CDEFS_H__ */
