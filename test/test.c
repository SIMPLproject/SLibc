#include <stdio.h>
#include <string.h>

int test(char *str) {

	if (strlen(str) == 3)
		return 1;
	else if (strlen(str) == 5)
		return 2;

	return 3;
}

int main(int ac, char **av) {
	printf("ac %d\n", ac);
	if (ac < 3)
		return 4;
	return test(av[1]);
}
