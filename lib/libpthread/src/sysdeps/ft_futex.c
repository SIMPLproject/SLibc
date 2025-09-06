#include <sys/syscall.h>
#include <stdatomic.h>

#include "ft_futex.h"

int futex(int *uaddr, int futex_op, int val, const struct timespec *timeout, int *uaddr2, int val3)
{
	int current = atomic_load_explicit((atomic_int *)uaddr, memory_order_acquire);

    if (current != val)
        return 0;

    return syscall(SYS_futex, uaddr, futex_op, val, timeout, uaddr2, val3);
}

/* int futex_wait_op(int *uaddr, int val, int val3) */

int futex_wait(int *uaddr, int val) 
{
	int ret = futex(uaddr, FUTEX_WAIT, val, NULL, NULL, 0);
	return ret;
}


int futex_wake(int *uaddr, int val) 
{
	return futex(uaddr, FUTEX_WAKE, val, NULL, NULL, 0);
}

