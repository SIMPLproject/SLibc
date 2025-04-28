#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(char *str) {

	if (strlen(str) == 3)
		return 1;
	else if (strlen(str) == 5)
		return 2;

	return 3;
}

int main(int ac, char **av) {
	printf("%s ac %d\n", av[0], ac);
	if (ac < 3)
		return 4;

	char *str = malloc(test(av[1]));
	memcpy(str, av[1], strlen(av[1]));
	return *str;
}
