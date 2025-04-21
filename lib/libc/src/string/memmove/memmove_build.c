#include <config.h>

#define memmove __memmove
#include <string.h>
#undef memmove

#if defined(SHARED) && !defined(NATIVE)

simpl_func_ifunc_init(__memmove, void *, IFUNC_AVX | IFUNC_SSE, void *, const void *, size_t)

#else

#include <select_embed.h>
#include simpl_embed_name(memmove)

#endif

simpl_weak_alias(memmove, __memmove)
