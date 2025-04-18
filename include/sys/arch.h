#ifndef __ARCH_H__
#define __ARCH_H__

/* Determine architecture width */
#if defined __x86_64__ && !defined __ILP32__
# define __ARCH_WIDTH 64
#else
# define __ARCH_WIDTH 32
#endif

#endif /* __ARCH_H__ */
