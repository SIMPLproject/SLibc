#include <config.h>

#define strchr _strchr
#include <string.h>
#undef strchr

simpl_func_ifunc_init(_strchr, char *, IFUNC_AVX, const char *, int);

simpl_weak_alias(strchr, _strchr)
