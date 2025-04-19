#include <config.h>

#define memmove _memmove
#include <string.h>
#undef memmove

#define _memmove FUNC_NAME(_memmove)

simpl_func_ifunc_init(_memmove, void *, IFUNC_AVX | IFUNC_SSE, void *, const void *, size_t)

simpl_weak_alias(memmove, _memmove)
