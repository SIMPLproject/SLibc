#include <stdint.h>
#include <config.h>

int	ARCH_SYM(strncmp)(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (first[i] == second[i] && first[i] && i < length - 1)
		i++;
	return ((unsigned char) first[i] - (unsigned char) second[i]);
}
