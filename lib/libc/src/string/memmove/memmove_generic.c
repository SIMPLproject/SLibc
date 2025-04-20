#include <stdlib.h>
#include <config.h>

void	*ARCH_SYM(memmove)(void *dest, const void *source, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;

	src = (unsigned char *) source;
	dst = (unsigned char *) dest;
	if (src == NULL && dst == NULL)
		return (dest);
	while (n--)
		*dst++ = *src++;
	return (dest);
}
