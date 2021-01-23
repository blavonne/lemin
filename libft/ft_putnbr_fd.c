/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:43:48 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/17 18:56:28 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(unsigned int nb, int fd)
{
	char	c;

	if (nb > 9)
		ft_putnbr_rec(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	ft_putnbr_rec(nb, fd);
}
