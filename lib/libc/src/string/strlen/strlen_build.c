#include <config.h>

#define strlen _strlen
#include <string.h>
#undef strlen

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(_strlen, size_t, IFUNC_AVX | IFUNC_SSE, const char *);

#else

#include <select_embed.h>
#include simpl_embed_name(strlen)

#endif

simpl_weak_alias(strlen, _strlen)
