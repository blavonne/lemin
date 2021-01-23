/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:59:00 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/17 19:05:58 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(long long int nb)
{
	int		c;

	if (nb > 9)
		ft_putnbr_rec(nb / 10);
	nb = nb % 10;
	c = (int)nb + '0';
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	long long int	nb;

	if (n < 0)
	{
		nb = n;
		nb = -nb;
		ft_putchar('-');
	}
	else
		nb = n;
	ft_putnbr_rec(nb);
}
