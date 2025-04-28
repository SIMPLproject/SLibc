#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__memset, void *, IFUNC_AVX | IFUNC_ERMS, void *, int c, size_t)

#else

#include <select_embed.h>
#include simpl_embed_name(memset)

#endif

libc_hidden_alias(memset, __memset)
simpl_weak_alias(memset, __memset)
