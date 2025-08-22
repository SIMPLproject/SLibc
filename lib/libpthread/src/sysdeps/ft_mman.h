/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:59:23 by babonnet          #+#    #+#             */
/*   Updated: 2024/10/13 16:02:37 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H
# define FT_MMAN_H

# include <stdio.h>

void	*ft_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int		ft_munmap(void *addr, size_t length);
int	ft_mprotect(void *addr, size_t len, int prot);

# define PROT_NONE 0x0
# define PROT_READ 0x1
# define PROT_WRITE 0x2
# define PROT_EXEC 0x4 
# define PROT_RW (PROT_WRITE | PROT_READ)

# define MAP_PRIVATE 0x02
# define MAP_ANONYMOUS 0x20

#endif /* FT_MMAN_H */
