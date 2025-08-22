#ifndef __LIBC_LINUX_86_64_BITS_TIME_H__
#define __LIBC_LINUX_86_64_BITS_TIME_H__

/* If the user asked for 64-bit time on 32-bit (Y2038-safe) */
#if defined(_TIME_BITS) && _TIME_BITS == 64
#  define __USE_TIME_BITS64 1
#endif

/* Decide the width of time_t (__TIMESIZE) if not already set.
   - On LP64 platforms, time_t is 64-bit by default.
   - On ILP32 platforms, it’s 32-bit unless _TIME_BITS=64 was requested. */
#ifndef __TIMESIZE
#  if defined(__LP64__) || defined(_LP64)
#    define __TIMESIZE 64
#  else
#    ifdef __USE_TIME_BITS64
#      define __TIMESIZE 64
#    else
#      define __TIMESIZE 32
#    endif
#  endif
#endif

#endif // __LIBC_LINUX_86_64_BITS_TIME_H__
