#include "func_ifunc_selector.h"
#include <config.h>
#define strncpy _strncpy
#include <string.h>
#undef strncpy

simpl_func_ifunc_init(_strncpy, char *, IFUNC_AVX | IFUNC_SSE, char *, const char *, size_t)  

simpl_weak_alias(strncpy, _strncpy)
