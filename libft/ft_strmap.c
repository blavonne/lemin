/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:36 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/14 19:11:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buf;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	buf = ft_strnew(ft_strlen(s));
	if (buf)
	{
		while (s[i])
		{
			buf[i] = f(s[i]);
			i++;
		}
	}
	else
		return (NULL);
	return (buf);
}
