#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__strchr, char *, IFUNC_AVX | IFUNC_SSE, const char *, int);

#else

#include <select_embed.h>
#include simpl_embed_name(strchr)

#endif

libc_hidden_alias(strchr, __strchr)
simpl_weak_alias(strchr, __strchr)
