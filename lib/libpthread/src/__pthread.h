#ifndef __FT_PTHREAD_H
#define __FT_PTHREAD_H

#include <pthread.h>
#include <stdint.h>

#define DEFAULT_STACK_SIZE (8192 * 1024)
#define ALIGN_SIZE 16
#define ALIGN(x) (((x) + ALIGN_SIZE - 1) & ~(ALIGN_SIZE - 1))

#define THREAD_SIZE (ALIGN(sizeof(__pthread)))

typedef void *(*pthread_routine)(void *);

enum thread_status {
    TH_RUNNING,
    TH_JOINABLE,
};

typedef struct __pthread {
    // need to be at offset 0 to store in %fs register
    // for ft_pthread_self
    // change this part will break the ABI
    struct __pthread *tcb;
    void             *tls;
    struct __pthread *self;

    // thread settings
    // will not break the ABI
    void *mapped_region;
    int   mapped_size;
    void *stack;
    int   stack_size;
    int   tls_size;

    int             tid;
    int             id;
    pthread_routine routine;
    _Atomic int     thread_status;
    pthread_attr_t  attr;

    // user settings

    void *arg;
    void *ret;
} __pthread;

#endif /* __FT_PTHREAD_H */
