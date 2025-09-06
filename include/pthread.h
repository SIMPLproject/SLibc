#ifndef __PTHREAD_H__
#define __PTHREAD_H__

#include <stdint.h>

typedef struct s_pthread_attr {
    uint32_t stack_size;
} pthread_attr_t;

typedef uintptr_t pthread_t;


pthread_t *pthread_self(void);

int pthread_create(pthread_t *__restrict__ thread, const pthread_attr_t *__restrict__ attr,
                      void *(*start_routine)(void *), void *__restrict__ arg);

int pthread_join(pthread_t *thread, void **value_ptr);

int tsprintf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif /* __PTHREAD_H__ */
