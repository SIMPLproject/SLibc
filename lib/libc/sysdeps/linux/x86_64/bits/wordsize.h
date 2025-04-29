#ifndef __WORDSIZE__
#define __WORDSIZE__

/* Determine architecture width */
#if defined __x86_64__ && !defined __ILP32__
# define __ARCH_WIDTH 64
#else
# define __ARCH_WIDTH 32
#endif

#define __WORDSIZE __ARCH_WIDTH

#endif /* __WORDSIZE__ */
