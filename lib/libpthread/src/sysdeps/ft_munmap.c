/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_munmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:59:17 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/17 13:30:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_syscall.h"
#include <sys/types.h>

int	ft_munmap(void *addr, size_t length)
{
	int	result;

	result = ft_syscall(SYS_MUNMAP, addr, length);
	if (result == -1)
	{
		return (-1);
	}
	return (0);
}
