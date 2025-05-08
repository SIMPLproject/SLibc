#include <auxv.h>
#include <link.h>
#include <machine.h>
#include <stdio.h>
#include <stdlib.h>

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

struct link_map {
    ElfW(Addr) l_addr;
    char *l_name;
    ElfW(Dyn) * l_dyn_section;
    struct link_map *l_next;
    struct link_map *l_prev;
};

struct link_map *init_link_map(const ElfW(Ehdr) * hdr_prgm);

// hdr_linker is just in the binary is depending on the linker to avoid
// remapping it
struct link_map *map_all_dependency(struct link_map* head_link_map, const ElfW(Ehdr) * hdr_linker);

void load_needed(struct link_map *);

void free_link_map(struct link_map* head_link_map);

void _ld_start(char **argv)
{
    const ElfW(Ehdr) *hdr_linker = get_linker_elf_hdr();
    const ElfW(Ehdr) *hdr_prgm = get_main_prgm_hdr_from_auxv(argv);

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
    _r_debug.r_map = head_link_map;
    _r_debug.r_state = RT_ADD;

    // - call constructor .init_arry
    // - find user entry
    // - call destructor .fini_array
    // free the entire struct (don't really needed because clear by linux but you now)
    exit(1);
}
