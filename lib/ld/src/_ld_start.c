#include "sys/cdefs.h"
#include <sys/symbols.h>

void __ld_start(void *arg)
{
    while (1)
    {
        arg += 1;
    }
	(void)arg;
}

simpl_weak_alias(_ld_start, __ld_start)

simpl_hidden_proto(_ld_start)
