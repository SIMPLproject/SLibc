#include <string.h>
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	/* char test[] = "ffffffffffffffffff"; */
	if (ac <= 1)
		return 1;
	int i = strlen(av[1]);
	printf("%d\n", i);
	(void)ac;
	(void)av;
	(void)env;
	
	char *str = "Hello, World!";
	printf("%s\n", str);
	memset(str, 'A', 5);
	printf("%p\n", str);
}

