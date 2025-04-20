#include "func_ifunc_selector.h"
#include <config.h>

#define memset _memset
#include <string.h>
#undef memset

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(_memset, void *, IFUNC_AVX | IFUNC_ERMS, void *, int c, size_t)

#else

#include <select_embed.h>
#include simpl_embed_name(memset)

#endif

simpl_weak_alias(memset, _memset)
