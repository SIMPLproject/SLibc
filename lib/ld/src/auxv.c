#include <auxv.h>
#include <link.h>
#include <stdlib.h>

void __set_auvx_list(auxv_list *auxv_lst, ElfW(auxv_t) * auxv_head_ptr)
{
    while (auxv_head_ptr->a_type != AT_NULL)
    {
        int type = auxv_head_ptr->a_type;
        auxv_lst->is_set[type] = true;
        auxv_lst->value[type] = auxv_head_ptr->a_un.a_val;
		auxv_head_ptr++;
    }
}

uint64_t __get_type_from_auxv(auxv_list *auxv_list, int type)
{
    if (auxv_list->is_set[type])
        return auxv_list->value[type];

    return -1;
}
