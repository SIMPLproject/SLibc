#include "link.h"
#include <stdio.h>
#include <machine.h>

void _ld_start(void *arg)
{
	ElfW(Ehdr) *hdr = (ElfW(Ehdr *))elf_machine_load_address();
	printf("[%p] %s\n", hdr, hdr->e_ident);
    (void)arg;
}
