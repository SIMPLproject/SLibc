#include "link.h"
#include "sys/symbols.h"
#include <stdio.h>
#include <machine.h>

void _ld_start(void *arg)
{
	const ElfW(Ehdr) *hdr = get_main_prgm_hdr();
	printf("[%p] %s\n", hdr, hdr->e_ident);
    (void)arg;
}

