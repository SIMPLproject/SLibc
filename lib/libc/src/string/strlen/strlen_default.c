#include <stdint.h>

size_t _strlen_default(const char *s) 
{
	const char *endptr;

	endptr = s;
	while (*endptr)
		endptr++;
	return (endptr - s);
}
