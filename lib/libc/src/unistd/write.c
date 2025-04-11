#include <config.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

ssize_t _write(int fildes, const void *buf, size_t nbyte) {
	return syscall(SYS_write, fildes, buf, nbyte);
}

simpl_weak_alias(write, _write)
