#include <config.h>

#define strlen __strlen
#include <string.h>
#undef strlen

#if defined(SHARED) && !defined(NATIVE)

/* simpl_func_ifunc_init(__strlen, size_t, IFUNC_AVX | IFUNC_SSE, const char *); */
extern size_t __strlen(const char *) __attribute__((ifunc("__strlen"
                                                          "_ifunc")));
size_t        __strlen_avx(const char *);
size_t        __strlen_sse(const char *);
size_t        __strlen_generic(const char *);
size_t (*__strlen_ifunc())(const char *)
{
    uint8_t version = IFUNC_AVX | IFUNC_SSE;
    if ((version & IFUNC_AVX) && simd_support.avx)
    {
        {
            return __strlen_avx;
        }
    }
    if ((version & IFUNC_SSE) && simd_support.sse)
    {
        {
            return __strlen_sse;
        }
    }
    {
        return __strlen_generic;
    }
}

#else

#include <select_embed.h>
#include simpl_embed_name(strlen)

#endif

simpl_weak_alias(strlen, __strlen)
