#ifndef __TIME_H__
#define __TIME_H__

#include "bits/time.h"

#include <stdint.h>

#if defined(__TIMESIZE) && __TIMESIZE == 64
#    define __TIME_IS_64 1
#elif defined(__USE_TIME_BITS64)
#    define __TIME_IS_64 1
#else
#    define __TIME_IS_64 0
#endif

/* Keep tv_nsec as long to match syscall ABI (__syscall_slong_t). */
#if __TIME_IS_64

struct timespec {
    int64_t tv_sec;  /* Seconds.       */
    long    tv_nsec; /* Nanoseconds.   */
};

#else /* 32-bit time_t ABI compatibility */

struct timespec {
    int32_t tv_sec; /* Seconds (32-bit). */
#    if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
    int32_t __pad;   /* Pad to align tv_nsec like kernel/glibc do. */
    long    tv_nsec; /* Nanoseconds. */
#    else
    long    tv_nsec; /* Nanoseconds. */
    int32_t __pad;   /* Pad to align tv_nsec like kernel/glibc do. */
#    endif
};

#endif

#endif // __TIME_H__
