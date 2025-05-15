#ifndef __AUXV_H__
#define __AUXV_H__

#include <link.h>

#define MAX_AUXV AT_MINSIGSTKSZ

typedef struct {
    bool			is_set[MAX_AUXV];
    ElfW(auxv_t)	value[MAX_AUXV];
} auxv_list;

#endif /* __AUXV_H__ */
