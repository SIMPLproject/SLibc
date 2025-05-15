#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__strlen, size_t, IFUNC_AVX | IFUNC_SSE, const char *);

#else

#include <select_embed.h>
#include simpl_embed_name(strlen)

#endif

libc_hidden_alias(strlen, __strlen)
simpl_weak_alias(strlen, __strlen)
