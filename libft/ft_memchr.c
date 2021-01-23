/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:50:55 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/17 23:31:56 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;

	cc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == cc)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
