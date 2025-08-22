/*
 * This file contains x86_64-specific implementations of built-in functions.
 * Fallback implementations are provided in include/sys/simpl_builtin.h.
 */

#ifndef __LIBC_LINUX_X86_64_BITS_SIMPL_BUILTIN_ARCH_H__
#define __LIBC_LINUX_X86_64_BITS_SIMPL_BUILTIN_ARCH_H__

#define CTZ(x) __builtin_ctz(x)

#define ALIGN_UP(x, a) __builtin_align_up(x, a)

#endif // __LIBC_LINUX_X86_64_BITS_SIMPL_BUILTIN_ARCH_H__
