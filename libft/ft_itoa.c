/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_iu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:43:59 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:54:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int decimal)
{
	int		len;
	int		temp;
	char	*res;
	int		index;

	len = 1;
	temp = decimal;
	while ((temp = temp / 10))
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	decimal < 0 ? res[0] = '-' : 0;
	while (len--)
	{
		index = ft_abs(decimal % 10);
		res[len] = RADIX[index];
		decimal /= 10;
	}
	return (res);
}

char	*ft_itoa_u(unsigned int decimal, int base)
{
	int				len;
	unsigned int	temp;
	char			*res;
	int				index;

	len = 1;
	temp = decimal;
	while ((temp = temp / base))
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		index = ft_abs((int)(decimal % base));
		res[len] = RADIX[index];
		decimal /= base;
	}
	return (res);
}
