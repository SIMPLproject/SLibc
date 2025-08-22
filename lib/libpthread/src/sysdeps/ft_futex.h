#ifndef FT_FUTEX_H
#define FT_FUTEX_H

#include <time.h>
#define FUTEX_WAIT 0
#define FUTEX_WAKE 1
#define FUTEX_FD 2
#define FUTEX_REQUEUE 3
#define FUTEX_CMP_REQUEUE 4
#define FUTEX_WAKE_OP 5
#define FUTEX_LOCK_PI 6
#define FUTEX_UNLOCK_PI 7
#define FUTEX_TRYLOCK_PI 8
#define FUTEX_WAIT_BITSET 9
#define FUTEX_WAKE_BITSET 10
#define FUTEX_WAIT_REQUEUE_PI 11
#define FUTEX_CMP_REQUEUE_PI 12

int ft_futex(int *uaddr, int futex_op, int val, const struct timespec *timeout, int *uaddr2, int val3);

int ft_futex_wait(int *uaddr, int val);
int ft_futex_wake(int *uaddr, int val);


#endif /* FT_FUTEX_H */
