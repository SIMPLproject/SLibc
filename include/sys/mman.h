#ifndef __SYS_MMAN_H__
#define __SYS_MMAN_H__

#include <stddef.h>
#include <sys/types.h>
#include <sys/symbols.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
libc_hidden_proto(mmap)

int   munmap(void *addr, size_t length);
libc_hidden_proto(munmap)

int   mprotect(void *addr, size_t len, int prot);
libc_hidden_proto(mprotect)

#define PROT_NONE 0x0
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_RW (PROT_WRITE | PROT_READ)

#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20
#define MAP_FAILED ((void *)-1)

#endif /* __SYS_MMAN_H__ */
