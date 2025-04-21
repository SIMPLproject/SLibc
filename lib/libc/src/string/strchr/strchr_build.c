#include <config.h>

#define strchr __strchr
#include <string.h>
#undef strchr

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__strchr, char *, IFUNC_AVX | IFUNC_SSE, const char *, int);

#else

#include <select_embed.h>
#include simpl_embed_name(strchr)

#endif

simpl_weak_alias(strchr, __strchr)
