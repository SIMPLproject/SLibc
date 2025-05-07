#include <auxv.h>
#include <link.h>
#include <stdlib.h>

const ElfW(Ehdr) * get_main_prgm_hdr_from_auxv(void *argv)
{
    Elf_auxv_t *auxv = get_auxv_from_argv(argv);

    while (auxv->a_type != AT_NULL)
    {
        if (auxv->a_type == AT_PHDR)
        {
            return (ElfW(Ehdr) *)auxv->a_un.a_val - 1;
        }
        auxv++;
    }
    return NULL;
}
