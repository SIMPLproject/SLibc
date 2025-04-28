#include <string.h>
#include <sys/cdefs.h>
#include <stdlib.h>

void _ld_start(void *arg)
{
	char *str;
	str = __malloc(strlen("test"));
	str = malloc(strlen(("test")));
    while (1)
    {
        arg += 1;
    }
	(void)str;
    (void)arg;
}
