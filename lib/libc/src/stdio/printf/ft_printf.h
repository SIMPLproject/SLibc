/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:35 by bbonnet           #+#    #+#             */
/*   Updated: 2025/04/28 20:21:17 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int ft_printf(const char *format, ...);

__hidden void ft_putchar_fd(char c, int fd);
__hidden void ft_putstr_fd(char *s, int fd);
__hidden void ft_putnbr_base(unsigned long n, char *base, unsigned long base_size, int *count);
__hidden void ft_putnbr_count(int n, int *count);
__hidden int  manage_char(va_list var, const char type);
__hidden int  print_pointer(unsigned long pointer);
__hidden int  display_wrong_flag(char c);
__hidden void ft_putsizet(size_t n);

#endif
