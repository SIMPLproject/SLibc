/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:47:04 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/17 13:30:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_syscall.h"
#include <sys/types.h>
#include <stdlib.h>

void	*ft_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	void	*result;

	result = (void *)ft_syscall(SYS_MMAP, addr, length, prot, flags, fd, offset);
	if (result == (void *)-1)
		return (NULL);
	return (result);
}
