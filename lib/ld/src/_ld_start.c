#include <link.h>
#include <stdio.h>
#include <stdlib.h>
#include <machine.h>
#include <auxv.h>

static const ElfW(Ehdr) *get_main_prgm_hdr(void *arg) {
	const ElfW(Ehdr) *hdr = NULL;//get_main_prgm_hdr_form_main_linker();

	if (hdr)
		return hdr;

	return get_main_prgm_hdr_from_auxv(arg);
}

void _ld_start(char **argv)
{
	const ElfW(Ehdr) *hdr = get_main_prgm_hdr(argv);
	printf("[%p] %s\n", hdr, hdr->e_ident);
}

