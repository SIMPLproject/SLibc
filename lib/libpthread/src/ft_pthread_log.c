#include "__ft_pthread.h"
#include "ft_pthread_log.h"
#include <stdarg.h>
#include <stdio.h>

static void __ft_pthread_vlog(t_pthread *thread, const char *msg, va_list arg)
{
	char msg_buff[256];

	__pthread *tp = (__pthread *)*thread;
	vsnprintf(msg_buff, 256, msg, arg);
    ft_tsprintf("[ft_pthread] Thread address: %p | Thread ID: %d | Status %s | Message: %s\n", tp,
                tp->id, TH_STATUS(tp), msg_buff);
}

/*
 *  log the thread data with a thread safe print
 */
void __ft_pthread_log(t_pthread *thread, const char *msg, ...)
{
    va_list lst;

    va_start(lst, msg);
    __ft_pthread_vlog(thread, msg, lst);
    va_end(lst);
}

/*
 * use the ft_pthread_log data but use the %fs register
 * to retrive the thread data
 */
void __ft_pthread_log_self(const char *msg, ...)
{
    t_pthread *self = ft_pthread_self();
    va_list    lst;

    va_start(lst, msg);
    __ft_pthread_vlog(self, msg, lst);
    va_end(lst);
}
