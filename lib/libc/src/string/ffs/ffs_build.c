#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__ffs, int, IFUNC_AVX | IFUNC_SSE, const char *, const char *)

#else

#include <select_embed.h>
#include simpl_embed_name(ffs)

#endif

libc_hidden_alias(ffs, __ffs)
simpl_weak_alias(ffs, __ffs)
