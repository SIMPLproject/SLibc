#include <config.h>
#include <sys/symbols.h>

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__memmove, void *, IFUNC_AVX | IFUNC_SSE, void *, const void *, size_t)

#else

#include <select_embed.h>
#include simpl_embed_name(memmove)

#endif

libc_hidden_alias(memmove, __memmove)
simpl_weak_alias(memmove, __memmove)
