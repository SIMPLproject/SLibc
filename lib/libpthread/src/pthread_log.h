#include <pthread.h>

#ifdef THREAD_LOG
#    define ft_pthread_log(...) __ft_pthread_log(__VA_ARGS__)
#    define ft_pthread_log_self(...) __ft_pthread_log_self(__VA_ARGS__)
#else
#    define ft_pthread_log(...)
#    define ft_pthread_log_self(...)
#endif

#define TH_STATUS(x) x->thread_status == TH_RUNNING ? "TH_RUNNING" : "TH_JOINABLE"

/*
 *  log the thread data with a thread safe print
 */
void __ft_pthread_log(pthread_t *thread, const char *msg, ...);

/*
 * use the ft_pthread_log data but use the %fs register
 * to retrive the thread data
 */
void __ft_pthread_log_self(const char *msg, ...);
