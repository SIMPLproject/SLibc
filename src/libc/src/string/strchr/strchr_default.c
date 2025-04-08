#include <string.h>

char *_strchr_default(const char *s, int c) {
	if (!s) return 0;
	while (*s && *s != (char)c) {
		s++;
	}
	return (*s == (char)c) ? (char *)s : 0;
}
