#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__strcmp, int, IFUNC_AVX | IFUNC_SSE, const char *, const char *)

#else

#include <select_embed.h>
#include simpl_embed_name(strcmp)

#endif

libc_hidden_alias(strcmp, __strcmp)
simpl_weak_alias(strcmp, __strcmp)
