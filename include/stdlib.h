#ifndef __STDLIB_H__
#define __STDLIB_H__

#if defined(__cplusplus) && __cplusplus >= 201103L
#    define NULL nullptr
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202300L
#    define NULL nullptr
#else
#    define NULL (void *)0
#endif
#include <stddef.h>
#include <sys/symbols.h>

void exit(int status);

void *malloc(size_t size);

// the hidden proto is set to __malloc but not malloc because the user should be able to replace
// malloc so malloc inside the libc should pass by the plt so this __malloc is for code that can't
// use plt like ld.so
void *__malloc(size_t size);
libc_hidden_proto(__malloc);

void free(void *ptr);
#endif // __STDLIB_H__
