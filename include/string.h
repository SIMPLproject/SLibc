#ifndef __STRING_H__
#define __STRING_H__

#include <stddef.h>
#include <sys/cdefs.h>


size_t strlen (const char *__s) __attribute_pure__ __nonnull(1);

int strncmp (const char *__s1, const char *__s2, size_t len) __attribute_pure__ __nonnull(1, 2);

int strcmp (const char *__s1, const char *__s2) __attribute_pure__ __nonnull(1, 2);

void *memset (void *__s, int __c, size_t __n) __nonnull (1);

void *memmove(void *dest, const void *src, size_t len) __nonnull(1, 2);

void *memcpy (void *__d, const void *__s, size_t __n) __nonnull (1, 2);

char *strncpy (char *__d, const char *__s, size_t __n) __nonnull (1, 2);

#endif // __STRING_H__
