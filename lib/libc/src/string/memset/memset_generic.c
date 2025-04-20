#include <stdint.h>
#include <config.h>

void	*ARCH_SYM(memset)(void *s, int c, size_t n)
{
	uint8_t	*ptr;

	if (s)
	{
		ptr = (uint8_t *)s;
		while (n--)
			*ptr++ = c;
	}
	return (s);
}
