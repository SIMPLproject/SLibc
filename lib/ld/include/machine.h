#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <link.h>
#include <sys/cdefs.h>

static inline ElfW(Addr) elf_machine_load_address(void)
{
    extern const ElfW(Ehdr) __ehdr_start __hidden;
    return (ElfW(Addr)) & __ehdr_start;
}

#include <__bits/machine.h>

#endif /* __MACHINE_H__ */
