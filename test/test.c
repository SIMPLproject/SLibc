
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac > 1)
        printf("size %lu\n", strlen(av[1]));
}
