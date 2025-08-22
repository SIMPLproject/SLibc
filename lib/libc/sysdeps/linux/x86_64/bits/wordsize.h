#ifndef __LIBC_LINUX_86_64_BITS_WORDSIZE__
#define __LIBC_LINUX_86_64_BITS_WORDSIZE__

/* Determine architecture width */
#if defined __x86_64__ && !defined __ILP32__
# define __ARCH_WIDTH 64
#else
# define __ARCH_WIDTH 32
#endif

#define __WORDSIZE __ARCH_WIDTH

#endif /* __LIBC_LINUX_86_64_BITS_WORDSIZE__ */
