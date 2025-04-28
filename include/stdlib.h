#ifndef __STDLIB_H__
#define __STDLIB_H__

#if defined(__cplusplus) && __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202300L
#define NULL nullptr
#else
#define NULL (void *)0
#endif
#include <stddef.h>
#include <sys/symbols.h>

void exit(int status);

void *malloc(size_t size);
libc_hidden_proto(malloc);
void free(void *ptr);
#endif // __STDLIB_H__
