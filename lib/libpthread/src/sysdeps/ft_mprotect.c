/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mprotect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:57:35 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/17 13:29:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_syscall.h"
#include <sys/types.h>

int	ft_mprotect(void *addr, size_t len, int prot)
{
	return (ft_syscall(SYS_MPROTECT, addr, len, prot));
}
