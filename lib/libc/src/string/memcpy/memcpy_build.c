#include <config.h>

#define memcpy __memcpy
#include <string.h>
#undef memcpy

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__memcpy, void *, IFUNC_AVX | IFUNC_SSE, void *, const void *, size_t)

#else

#include <select_embed.h>
#include simpl_embed_name(memcpy)

#endif

simpl_weak_alias(memcpy, __memcpy)
