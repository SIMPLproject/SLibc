#include <stdint.h>
#include <config.h>

size_t ARCH_SYM(strlen)(const char *s) 
{
	const char *endptr;

	endptr = s;
	while (*endptr)
		endptr++;
	return (endptr - s);
}
