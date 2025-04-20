#include <string.h>
#include <config.h>


char *ARCH_SYM(strchr)(const char *s, int c) {
	if (!s) return 0;
	while (*s && *s != (char)c) {
		s++;
	}
	return (*s == (char)c) ? (char *)s : 0;
}
