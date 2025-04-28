#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__strncmp, int, IFUNC_AVX | IFUNC_SSE, const char *, const char *, size_t)  

#else

#include <select_embed.h>
#include simpl_embed_name(strncmp)

#endif

libc_hidden_alias(strncmp, __strncmp)
simpl_weak_alias(strncmp, __strncmp)
