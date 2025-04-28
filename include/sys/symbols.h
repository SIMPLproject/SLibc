#ifndef __SYS_SYMBOLS_H__
#define __SYS_SYMBOLS_H__

#include <sys/cdefs.h>

#define SIMPL_INTERNAL_SYMBOL "__SI_"

#define simpl_hidden_proto(name)                                                                   \
    extern __typeof(name) name __asm__(SIMPL_INTERNAL_SYMBOL #name) __hidden;

#define simpl_hidden_def(name) simpl_strong_alias(__SI_##name, name)

#define simpl_hidden_alias(name, src)                                                              \
    extern __typeof__(src) __SI_##name __attribute__((alias(#src)));

#if defined(IN_libc) || defined(IN_ld)
#    define libc_hidden_def(name) simpl_hidden_def(name)
#    define libc_hidden_proto(name) simpl_hidden_proto(name)
#    define libc_hidden_alias(name, src) simpl_hidden_alias(name, src)
#else
#    define libc_hidden_def(name)
#    define libc_hidden_proto(name)
#    define libc_hidden_alias(name, src)
#endif

#endif /* __SYS_SYMBOLS_H__ */
