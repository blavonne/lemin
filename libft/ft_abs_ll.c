/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:19:21 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:19:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_abs_ll(int nbr)
{
	long long int	tmp;

	tmp = nbr;
	if (nbr < 0)
		return (-tmp);
	else
		return (tmp);
}
