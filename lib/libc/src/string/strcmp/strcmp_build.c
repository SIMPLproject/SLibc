#include <config.h>

#define strcmp _strcmp
#include <string.h>
#undef strcmp

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(_strcmp, int, IFUNC_AVX | IFUNC_SSE, const char *, const char *)

#else

#include <select_embed.h>
#include simpl_embed_name(strcmp)

#endif

simpl_weak_alias(strcmp, _strcmp)
