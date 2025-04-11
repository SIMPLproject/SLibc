#ifndef __UNISTD_H__
#define __UNISTD_H__

typedef long int          ssize_t;
typedef unsigned long int size_t;

long syscall(long number, ...);

void exit(int status);

ssize_t write(int fildes, const void *buf, size_t nbyte);

ssize_t read(int fd, void *buf, size_t count);

#endif // __UNISTD_H__
