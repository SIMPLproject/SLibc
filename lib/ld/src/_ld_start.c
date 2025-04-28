#include <string.h>
#include <sys/cdefs.h>
#include <stdlib.h>

void _ld_start(void *arg)
{
	char *str;
	str = malloc(strlen((char *)arg));
    while (1)
    {
        arg += 1;
    }
	(void)str;
    (void)arg;
}
