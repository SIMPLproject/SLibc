#ifndef FT_PTHREAD_ARCH_H
#define FT_PTHREAD_ARCH_H

#include <stdint.h>

#define ARCH_SET_FS 0x1002

uintptr_t __get_tp(void);
void      __set_tp(uintptr_t tp);

#endif /* FT_PTHREAD_ARCH_H */
