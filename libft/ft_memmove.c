/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:50:35 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/10 22:16:02 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_d;
	const char	*tmp_s;
	size_t		i;

	i = 0;
	tmp_d = dst;
	tmp_s = src;
	if (tmp_s < tmp_d)
		while (len > 0)
		{
			tmp_d[len - 1] = tmp_s[len - 1];
			len--;
		}
	else if (tmp_s > tmp_d)
		while (i < len)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	return (dst);
}
