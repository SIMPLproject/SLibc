#include <config.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

ssize_t _read(int fd, void *buf, size_t count) {
	return syscall(SYS_read, fd, buf, count);
}

simpl_weak_alias(read, _read)
