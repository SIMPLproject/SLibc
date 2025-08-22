#ifndef FT_PTHREAD_H
#define FT_PTHREAD_H

#include "pthread.h"
#include <stdatomic.h>
#include <stdint.h>


typedef struct s_pthread_attr {
    uint32_t stack_size;
} t_pthread_attr;

typedef uintptr_t t_pthread;


t_pthread *ft_pthread_self(void);

int ft_pthread_create(t_pthread *__restrict__ thread, const t_pthread_attr *__restrict__ attr,
                      void *(*start_routine)(void *), void *__restrict__ arg);

int ft_pthread_join(t_pthread *thread, void **value_ptr);

int ft_tsprintf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif /* FT_PTHREAD_H */
