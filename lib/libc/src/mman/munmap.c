#include "sys/cdefs.h"
#include "sys/symbols.h"
#include <errno.h>
#include <sys/syscall.h>
#include <unistd.h>

int   __munmap(void *addr, size_t length)
{
    long ret = syscall(SYS_munmap, addr, length);

    if (ret < 0)
    {
        errno = -ret;
        return -1;
    }
    return 0;
}

simpl_weak_alias(munmap, __munmap)
simpl_hidden_alias(munmap, __munmap)
