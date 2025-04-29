#ifndef __SYS_SYMBOLS_H__
#define __SYS_SYMBOLS_H__

#ifndef __ASSEMBLER__

#    include <sys/cdefs.h>

#    define SIMPL_INTERNAL_SYMBOL_STRING "__SI_"
#    define SIMPL_INTERNAL_SYMBOL(x) __SI_##x

#    define simpl_hidden_proto(name)                                                               \
        extern __typeof(name) name __asm__(SIMPL_INTERNAL_SYMBOL_STRING #name) __hidden;

#    define simpl_hidden_def(name) simpl_strong_alias(__SI_##name, name)

#    define simpl_hidden_alias(name, src)                                                          \
        extern __typeof__(src) __SI_##name __attribute__((alias(#src)));

#    if defined(IN_libc) || defined(IN_ld)
#        define libc_hidden_def(name) simpl_hidden_def(name)
#        define libc_hidden_proto(name) simpl_hidden_proto(name)
#        define libc_hidden_alias(name, src) simpl_hidden_alias(name, src)
#    else
#        define libc_hidden_def(name)
#        define libc_hidden_proto(name)
#        define libc_hidden_alias(name, src)
#    endif

#else /* ifdef __ASSEMBLY__ */

#    define SIMPL_INTERNAL_SYMBOL_DEF(x) \
.extern x \
.hidden x

#endif /* __ASSEMBLY__ */

#endif /* __SYS_SYMBOLS_H__ */
