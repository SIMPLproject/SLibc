#include <auxv.h>
#include <machine.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "__link.h"

/*
 * Debugging descriptor for debuggers (GDB uses this)
 */
struct r_debug _r_debug = {
    .r_version = 1,           //
    .r_map = 0,               //
    .r_brk = 0,               //
    .r_state = RT_CONSISTENT, //
    .r_ldbase = 0             //
};

static struct __link_map *init_link_map(const ElfW(Ehdr) * hdr_prgm)
{
    struct __link_map *new = __malloc(sizeof(struct __link_map));
    if (new == NULL)
        return NULL;

    memset(new, 0, sizeof(struct __link_map));
	return new;
}

// hdr_linker is just in the binary is depending on the linker to avoid
// remapping it
static struct __link_map *map_all_dependency(struct __link_map *head_link_map, const ElfW(Ehdr) * hdr_linker)
{
	(void)head_link_map;
	(void)hdr_linker;
	return NULL;
}

static void load_needed(struct __link_map *oui) {
	(void)oui;
}

static void free_link_map(struct __link_map *head_link_map) { (void)head_link_map; }

void _ld_start(char **argv)
{
	auxv_list auxv_lst;

	__set_auvx_list(&auxv_lst, get_auxv_from_argv(argv));
	
    const ElfW(Ehdr) *hdr_linker = get_linker_elf_hdr();
    const ElfW(Ehdr) *hdr_prgm  = (ElfW(Ehdr) *)__get_type_from_auxv(&auxv_lst, AT_PHDR);

    printf("[%p] %s\n", hdr_linker, hdr_linker->e_ident);
    printf("[%p] %s\n", hdr_prgm, hdr_prgm->e_ident);

    // allocated all depency needed by the prgm
    struct __link_map *head_link_map = init_link_map(hdr_prgm);
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
