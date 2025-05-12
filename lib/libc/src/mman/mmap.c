#define _LARGEFILE64_SOURCE
#include <errno.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

void *__mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    long ret = syscall(SYS_mmap, addr, length, prot, flags, fd, offset);

    if (ret < 0)
    {
        errno = -ret;
        return MAP_FAILED;
    }
    return (void *)ret;
}

simpl_weak_alias(mmap, __mmap)
simpl_hidden_alias(mmap, __mmap)
