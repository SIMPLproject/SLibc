#ifndef __UNISTD_H__
#define __UNISTD_H__

long _syscall(long number, ...);

void _exit(int status);

int write(int fildes, const void *buf, unsigned int nbyte);

#endif // __UNISTD_H__
