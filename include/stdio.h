#ifndef __STDIO_H__
#define __STDIO_H__

#include <sys/symbols.h>
int printf(const char *format, ...);
libc_hidden_proto(printf)

// to rm no link with 42....
int ft_printf(const char *format, ...);

int putchar(char c);

int puts( const char* str);
libc_hidden_proto(puts)

#endif // __STDIO_H__
