#include <config.h>

#define strncmp _strncmp
#include <string.h>
#undef strncmp

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(_strncmp, int, IFUNC_AVX | IFUNC_SSE, const char *, const char *, size_t)  

#else

#include <select_embed.h>
#include simpl_embed_name(strncmp)

#endif

simpl_weak_alias(strncmp, _strncmp)
