#ifndef __AUXV_H__
#define __AUXV_H__

#include <link.h>
#include <sys/cdefs.h>

#define MAX_AUXV AT_MINSIGSTKSZ

typedef struct {
    bool     is_set[MAX_AUXV];
    uint64_t value[MAX_AUXV];
} auxv_list;

static inline Elf_auxv_t *get_auxv_from_env(char **env)
{
    while (*env)
        env++;
    return (Elf_auxv_t *)++env;
}

static inline Elf_auxv_t *get_auxv_from_argv(char **argv)
{
    while (*argv)
        argv++;
    return get_auxv_from_env(++argv);
}

uint64_t __get_type_from_auxv(auxv_list *auxv_list, int type) __hidden;

void __set_auvx_list(auxv_list *auxv_lst, ElfW(auxv_t) * auxv_head_ptr) __hidden;

#endif /* __AUXV_H__ */
