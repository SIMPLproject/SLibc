#include <libc/auxv.h>
#include <libc/machine.h>
#include <libc/ld_debug.h>
#include <libc/ld_relocate.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <link.h>

static struct link_map *init_link_map(const ElfW(Ehdr) * hdr_prgm)
{
	(void)hdr_prgm;
    struct link_map *new = malloc(sizeof(struct link_map));
    if (new == NULL)
        return NULL;

    memset(new, 0, sizeof(struct link_map));
	return new;
}

// hdr_linker is just in the binary is depending on the linker to avoid
// remapping it
static struct link_map *map_all_dependency(struct link_map *head_link_map, const ElfW(Ehdr) * hdr_linker)
{
	(void)head_link_map;
	(void)hdr_linker;
	return NULL;
}

static void load_needed(struct link_map *oui) {
	(void)oui;
}

static void free_link_map(struct link_map *head_link_map) { (void)head_link_map; }

void _ld_start(char **argv)
{
	auxv_list auxv_lst;

	__set_auvx_list(&auxv_lst, get_auxv_from_argv(argv));
	
    const ElfW(Ehdr) *hdr_linker = get_pgrm_elf_hdr();
    const ElfW(Ehdr) *hdr_prgm  = (ElfW(Ehdr) *)__get_type_from_auxv(&auxv_lst, AT_PHDR);
	const ElfW(Dyn) __attribute__((unused)) *dyn = get_machine_dynamic();

	__dl_relocate_dyn_symbol(hdr_linker, dyn);

    printf("[%p] %s\n", hdr_linker, hdr_linker->e_ident);
    printf("[%p] %s\n", hdr_prgm, hdr_prgm->e_ident);

    // allocated all depency needed by the prgm
    struct link_map *head_link_map = init_link_map(hdr_prgm);
    if (head_link_map == NULL)
        exit(1);

    if (map_all_dependency(head_link_map, hdr_prgm))
    {
        free_link_map(head_link_map);
        exit(1);
    }

    // resolution of all DT_NEEDED
    load_needed(head_link_map);

    _r_debug.r_ldbase = (ElfW(Addr))hdr_linker;
    _r_debug.r_map = (struct link_map *)head_link_map;
    _r_debug.r_state = RT_ADD;

    // - call constructor .init_arry
    // - find user entry
    // - call destructor .fini_array
    // free the entire struct (don't really needed because clear by linux but you now)
    exit(1);
}
