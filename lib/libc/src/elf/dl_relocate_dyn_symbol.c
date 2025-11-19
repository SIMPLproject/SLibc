#include "link.h"
#include "stdio.h"

#define __ELF_ENUMS_STRINGIFY
#include "elf_identifier.h"

void __dl_relocate_dyn_symbol([[maybe_unused]] const ElfW(Ehdr) *ehdr, const ElfW(Dyn) *dyn) {

	for (ElfW(Dyn) *d = (ElfW(Dyn)*)dyn; d->d_tag != DT_NULL; d++) {
		printf("%s\n", ELF_DynamicTag_stringify(d->d_tag));
	}
	
}
