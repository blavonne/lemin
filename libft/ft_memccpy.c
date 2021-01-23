/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:50:19 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/13 23:37:06 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp_s;
	unsigned char		*tmp_d;
	size_t				i;

	i = 0;
	tmp_d = (unsigned char *)dst;
	tmp_s = (unsigned char *)src;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		if (tmp_s[i] == (unsigned char)c)
			return (&tmp_d[i + 1]);
		i++;
	}
	return (NULL);
}
