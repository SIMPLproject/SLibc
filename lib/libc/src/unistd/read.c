#include <sys/symbols.h>
#include <config.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

ssize_t __read(int fd, void *buf, size_t count) {
	return syscall(SYS_read, fd, buf, count);
}

simpl_weak_alias(read, __read)
libc_hidden_alias(read, __read)
