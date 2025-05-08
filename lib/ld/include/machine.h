#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <link.h>
#include <sys/cdefs.h>

/**
 * get_linker_elf_hdr — Get a pointer to the ELF header of the main program.
 *
 * __ehdr_start is a hidden symbol provided by the linker (via the dynamic
 * loader’s startup code).  It points at the very beginning of the ELF
 * header for the executable.
 *
 * or like gnu said it's **magically** define by the linker
 */
static inline const ElfW(Ehdr) *get_linker_elf_hdr(void)
{
    extern const ElfW(Ehdr) __ehdr_start __hidden;
    return &__ehdr_start;
}

#include <__bits/machine.h>

#endif /* __MACHINE_H__ */
