/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:19:35 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:19:38 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!i && ft_issign(str[i]))
			i++;
		if (!str[i] || !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
