
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s <string>\n", av[0]);
		return 1;
	}
	
	if (strcmp(av[1], "exit") == 0)
		return 23;
	
	if (strcmp(av[1], "exit2") == 0)
	{
		void *p = 0x0;
		void* dest = 0x00;
		memcpy(dest, p, 0x100);
		return 23;
	}	
	while (1) {}
}

