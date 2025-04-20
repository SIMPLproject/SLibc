#include <config.h>
#define strncpy _strncpy
#include <string.h>
#undef strncpy

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(_strncpy, char *, IFUNC_AVX | IFUNC_SSE, char *, const char *, size_t)  

#else

#include <select_embed.h>
#include simpl_embed_name(strncpy)

#endif

simpl_weak_alias(strncpy, _strncpy)
