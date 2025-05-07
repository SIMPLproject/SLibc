#include <link.h>
#include <stdio.h>
#include <machine.h>
#include <auxv.h>
#include <stdlib.h>

static const ElfW(Ehdr) *get_main_prgm_hdr(void *arg) {
	const ElfW(Ehdr) *hdr = get_main_prgm_hdr_form_main_linker();

	if (hdr)
		return hdr;

	// might need to alloc it and stuff or that **magic** like when
	// glibc talk about __ehdr_start 
	return get_main_prgm_hdr_from_auxv(arg);
}

void _ld_start(char **argv)
{
	const ElfW(Ehdr) *hdr = get_main_prgm_hdr(argv);
	printf("[%p] %s\n", hdr, hdr->e_ident);
	exit(1);
}

