
#include <config.h>
#include <bits/simpl_builtin_arch.h>

int ARCH_SYM(ffs)(int x) { return CTZ(x); }
