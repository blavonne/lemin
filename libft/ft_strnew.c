/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:17:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:57:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*obj;

	if (size + 1 == 0)
		return (NULL);
	obj = 0;
	if (!(obj = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(obj, size + 1);
	return (obj);
}
