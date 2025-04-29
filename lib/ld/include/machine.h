#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <link.h>
#include <sys/cdefs.h>

static inline const ElfW(Ehdr) *get_main_prgm_hdr(void)
{
    extern const ElfW(Ehdr) __ehdr_start __hidden;
    return & __ehdr_start;
}

#include <__bits/machine.h>

#endif /* __MACHINE_H__ */
