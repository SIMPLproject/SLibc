/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:11:15 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/17 13:30:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>

struct s_syscall_args {
    uint64_t rax;
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rdx;
    uint64_t r10;
    uint64_t r8;
    uint64_t r9;
};

long ft_syscall(long number, ...);

#ifdef __APPLE__
#    define SYS_THREAD_SELFID 372
#    define SYS_FUTEX 240
#    define SYS_SEM_WAIT 393
#    define SYS_SEM_POST 394
#    define SYS_MACH_SEMAPHORE_WAIT 341
#    define SYS_MACH_SEMAPHORE_SIGNAL 342
#    define SYS_WRITE 4
#    define SYS_MMAP 197
#    define SYS_MUNMAP 73
#    define SYS_MPROTECT 74

#else
#    define SYS_CLONE 56
#    define SYS_clone3 435
#    define SYS_FUTEX 202
#    define SYS_SET_TLS 234
#    define SYS_EXIT 60
#    define SYS_NANOSLEEP 35
#    define SYS_GETTID 186
#    define SYS_TGKILL 234
#    define SYS_WAIT4 61
#    define SYS_RT_SIGPROCMASK 14
#    define SYS_RT_SIGSUSPEND 15
#    define SYS_WRITE 1
#    define SYS_MMAP 9
#    define SYS_MPROTECT 10
#    define SYS_MUNMAP 11
#    define SYS_futex 202
#    define SYS_gettid 186
#    define SYS_arch_prctl 158
#endif

#endif /* SYSCALL_H */
