/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:22:00 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/18 21:20:31 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s1;
	char	*s2;
	size_t	len_new;
	size_t	len_d;

	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	s1 = (char *)dst;
	s2 = (char *)src;
	len_d = ft_strlen(dst);
	len_new = len_d + ft_strlen(s2);
	s1 += len_d;
	while (*s2 && len_d++ < size - 1)
		*s1++ = *s2++;
	*s1 = '\0';
	return (len_new);
}
