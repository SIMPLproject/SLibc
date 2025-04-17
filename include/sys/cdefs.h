#ifndef __CDEFS_H__
#define __CDEFS_H__

/* Compiler-specific attributes for alignment and inline functions */
#if defined(__clang__) || defined(__GNUC__)
# define _ALIGN(N) __attribute__((aligned(N)))
# define __Inline __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
# define __Inline __forceinline
# define _ALIGN(N)
#else
# define __Inline inline
# define _ALIGN(N)
#endif

#if defined (__GNUC__) || defined (__clang__)
#	undef __nonnull
#	define __nonnull(...) __attribute__ ((__nonnull__ (__VA_ARGS__)))
#else
#	define __nonnull(...)
#endif

#if defined (__GNUC__) || defined (__clang__)
# undef __attribute_pure__
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# define __attribute_pure__ /* Ignore */
#endif

#if defined(__linux__)
#define __unused __attribute__((unused))
#else
#define __unused
#endif


#if SHARED
# define simpl_hidden_def(name) \
	__asm__(".hidden " ## #name) __attribute__((hidden))
# define simpl_hidden_proto(name)
#else
# define simpl_hidden_def(name)
# define simpl_hidden_proto(name)
#endif

#endif /* __CDEFS_H__ */
