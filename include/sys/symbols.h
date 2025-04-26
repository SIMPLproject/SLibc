#ifndef __SYS_SYMBOLS_H__
#define __SYS_SYMBOLS_H__

#include <sys/cdefs.h>

#define SIMPL_INTERNAL_SYMBOL(x) __SI_##x

#ifdef SHARED
#    define simpl_hidden_def(name) strong_alias(SIMPSIMPL_INTERNAL_SYMBOL(name), name)

#    define simpl_hidden_proto(name)                                                               \
        extern __typeof(name) name __attribute__((visibility("hidden")));
#else
#    define simpl_hidden_def(name)

#    define simpl_hidden_proto(name)
#endif

#endif /* __SYS_SYMBOLS_H__ */
