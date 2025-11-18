#ifndef ____LINK_H__
#define ____LINK_H__

#include "link.h"

struct __link_map {
    ElfW(Addr) l_addr;
    char *l_name;
    ElfW(Dyn) * l_dyn_section;
    struct link_map *l_next;
    struct link_map *l_prev;
};

#endif // ____LINK_H__
