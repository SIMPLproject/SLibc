#include <stdint.h>
#include <config.h>

int ARCH_SYM(strcmp)(const char *s1, const char *s2) {
	if (!s1 || !s2) return 0;
	while (*s1 && *s1 == *s2) {
		s1++;
		s2++;
	}

	return *(unsigned char*)s1 - *(unsigned char*)s2;
}
