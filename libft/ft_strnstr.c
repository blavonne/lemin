/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:53:18 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/17 23:44:07 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*begin;
	char	*tmp;
	size_t	i;

	tmp = (char *)needle;
	if (!*needle)
		return ((char *)haystack);
	while (len > 0 && *haystack)
	{
		i = len--;
		if (*haystack == *needle)
		{
			begin = (char *)haystack;
			while (*haystack++ == *needle++ && i--)
				if (!*needle)
					return ((char *)begin);
			if (needle + 1 && (needle + 1 != haystack + 1))
			{
				haystack = begin;
				needle = tmp;
			}
		}
		haystack++;
	}
	return (NULL);
}
