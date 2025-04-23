#include <config.h>

#define memset __memset
#include <string.h>
#undef memset

#ifdef HAS_AVX
#warning "rewrerewkqjhrejhkwrejhkrweqjkhwreqjhklwreqjhkwreq"
#endif

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__memset, void *, IFUNC_AVX | IFUNC_ERMS, void *, int c, size_t)

#else

#include <select_embed.h>
#include simpl_embed_name(memset)

#endif

simpl_weak_alias(memset, __memset)
