#ifndef __UNISTD_H__
#define __UNISTD_H__

#include "sys/symbols.h"
typedef long int          ssize_t;
typedef unsigned long int size_t;

long syscall(long number, ...);
libc_hidden_proto(syscall)

void exit(int status);
libc_hidden_proto(exit)

ssize_t write(int fildes, const void *buf, size_t nbyte);
libc_hidden_proto(write)

ssize_t read(int fd, void *buf, size_t count);
libc_hidden_proto(read)

#endif // __UNISTD_H__
