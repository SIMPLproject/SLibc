#include "__ft_pthread.h"
#include "ft_pthread_log.h"
#include "sysdeps/ft_futex.h"
#include <errno.h>
#include <stdio.h>

int ft_pthread_join(t_pthread *thread, void **value_ptr)
{
	__pthread *tp = (__pthread *)*thread;
    ft_pthread_log(thread, "start join");
    while (atomic_load(&tp->thread_status) != TH_JOINABLE)
    {
        int current_state = atomic_load(&tp->thread_status);

        if (current_state != TH_JOINABLE)
        {
            ft_pthread_log(thread, "before wait");
            if (ft_futex_wait((int *)&tp->thread_status, current_state) == -1)
                return 1;
            ft_pthread_log(thread, "after wait");
        }
    }

    if (value_ptr != NULL)
        *value_ptr = tp->ret;

    ft_pthread_log(thread, "end join sucess");

    return 0;
}
