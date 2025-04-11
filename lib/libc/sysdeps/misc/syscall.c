#include <stdarg.h>
#include <sys/cdefs.h>
#include <errno.h>

long int syscall(long int callno __unused, ...)
{
	__set_errno(1);
	return -1;
}


