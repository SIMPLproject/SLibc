#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__strncpy, char *, IFUNC_AVX | IFUNC_SSE, char *, const char *, size_t)  

#else

#include <select_embed.h>
#include simpl_embed_name(strncpy)

#endif

libc_hidden_alias(strncpy, __strncpy)
simpl_weak_alias(strncpy, __strncpy)
