#include "sys/cdefs.h"
#include "sys/symbols.h"
#include <errno.h>
#include <sys/syscall.h>
#include <unistd.h>

int   __mprotect(void *addr, size_t len, int prot)
{
    long ret = syscall(SYS_mprotect, addr, len, prot);

    if (ret < 0)
    {
        errno = -ret;
        return -1;
    }
    return 0;
}

simpl_weak_alias(mprotect, __mprotect)
simpl_hidden_alias(mprotect, __mprotect)
