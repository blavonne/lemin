/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:57:02 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:57:04 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (size < ft_strlen(s1) || size < ft_strlen(s2))
		return (NULL);
	if (!(cat = ft_strnew(size)))
		return (NULL);
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	return (cat);
}
