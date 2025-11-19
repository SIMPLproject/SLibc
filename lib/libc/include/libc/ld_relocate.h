#ifndef __LD_RELOCATE_H__
#define __LD_RELOCATE_H__

#include "link.h"
#include "sys/cdefs.h"

void __dl_relocate_dyn_symbol(const ElfW(Ehdr) *ehdr, const ElfW(Dyn) *dyn) __hidden;

#endif // __LD_RELOCATE_H__
