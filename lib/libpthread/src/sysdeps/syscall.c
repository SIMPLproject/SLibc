/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:10:52 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/17 13:30:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_syscall.h"
#include <stdarg.h>
#include <stdint.h>

static void	syscall_get_args(va_list args, long number,
		struct s_syscall_args *sys_args)
{
	sys_args->rax = number;
	sys_args->rdi = va_arg(args, uint64_t);
	sys_args->rsi = va_arg(args, uint64_t);
	sys_args->rdx = va_arg(args, uint64_t);
	sys_args->r10 = va_arg(args, uint64_t);
	sys_args->r8 = va_arg(args, uint64_t);
	sys_args->r9 = va_arg(args, uint64_t);
}

#ifdef __APPLE__

static long	syscall_call(struct s_syscall_args *sys_args)
{
	long	ret;

	__asm__ volatile( "mov rax, %1 \n"
		"mov rdi, %2 \n"
		"mov rsi, %3 \n"
		"mov rdx, %4 \n"
		"mov r10, %5 \n"
		"mov r8, %6  \n"
		"mov r9, %7  \n"
		"syscall      \n"
		"mov rax, %0  \n"
		: "=r"(ret)
		: "r"(sys_args->rax), "r"(sys_args->rdi),
			"r"(sys_args->rsi), "r"(sys_args->rdx),
			"r"(sys_args->r10), "r"(sys_args->r8),
			"r"(sys_args->r9)
		: "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9",
			"memory");
	return (ret);
}

#elif __linux__

static long	syscall_call(struct s_syscall_args *sys_args)
{
	long	ret;

	__asm__ volatile( "mov %1, %%rax \n"
		"mov %2, %%rdi \n"
		"mov %3, %%rsi \n"
		"mov %4, %%rdx \n"
		"mov %5, %%r10 \n"
		"mov %6, %%r8  \n"
		"mov %7, %%r9  \n"
		"syscall        \n"
		"mov %%rax, %0  \n"
		: "=r"(ret)
		: "r"(sys_args->rax), "r"(sys_args->rdi),
			"r"(sys_args->rsi), "r"(sys_args->rdx),
			"r"(sys_args->r10), "r"(sys_args->r8),
			"r"(sys_args->r9)
		: "%rax", "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9",
			"memory");
	return (ret);
}

#endif

long	ft_syscall(long number, ...)
{
	struct s_syscall_args	sys_args;
	va_list					args;

	va_start(args, number);
	syscall_get_args(args, number, &sys_args);
	va_end(args);
	return (syscall_call(&sys_args));
}

