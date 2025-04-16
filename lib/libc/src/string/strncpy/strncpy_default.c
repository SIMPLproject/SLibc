#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char *_strncpy_default(char *dest, const char *src, size_t n) {
	if (!dest || !src) return NULL;
	char *d = dest;
	const char *s = src;
	while (n && (*d++ = *s++)) {
		n--;
	}
	if (n) {
		while (--n) {
			*d++ = '\0';
		}
	}
	return dest;
}
