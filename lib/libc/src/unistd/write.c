#include <sys/symbols.h>
#include <config.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

ssize_t __write(int fildes, const void *buf, size_t nbyte) {
	return syscall(SYS_write, fildes, buf, nbyte);
}

simpl_weak_alias(write, __write)
libc_hidden_alias(write, __write)
