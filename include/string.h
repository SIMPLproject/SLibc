#ifndef __STRING_H__
#define __STRING_H__

#include "sys/symbols.h"
#include <stddef.h>
#include <sys/cdefs.h>


size_t strlen (const char *__s) __attribute_pure__ __nonnull(1);
libc_hidden_proto(strlen)

int strncmp (const char *__s1, const char *__s2, size_t len) __attribute_pure__ __nonnull(1, 2);
libc_hidden_proto(strncmp)

int strcmp (const char *__s1, const char *__s2) __attribute_pure__ __nonnull(1, 2);
libc_hidden_proto(strcmp)

void *memset (void *__s, int __c, size_t __n) __nonnull (1);
libc_hidden_proto(memset)

void *memmove(void *dest, const void *src, size_t len) __nonnull(1, 2);
libc_hidden_proto(memmove)

void *memcpy (void *__d, const void *__s, size_t __n) __nonnull (1, 2);
libc_hidden_proto(memcpy)

char *strncpy (char *__d, const char *__s, size_t __n) __nonnull (1, 2);
libc_hidden_proto(strncpy)

#endif // __STRING_H__
