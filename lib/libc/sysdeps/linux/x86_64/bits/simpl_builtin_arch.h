/*
 * This file contains x86_64-specific implementations of built-in functions.
 * Fallback implementations are provided in include/sys/simpl_builtin.h.
 */

#ifndef __SIMPL_BUILTIN_ARCH_H__
#define __SIMPL_BUILTIN_ARCH_H__

#define CTZ(x) __builtin_ctz(x)

#define ALIGN_UP(x, a) __builtin_align_up(x, a)

#endif // __SIMPL_BUILTIN_ARCH_H__
