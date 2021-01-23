/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:52:24 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/16 22:04:19 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim(char c)
{
	if (c == ' ' || c == ',' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (is_trim(s[start]))
		start++;
	if (end == start)
		return (tmp = ft_strnew(0));
	while (is_trim(s[end - 1]))
		end--;
	tmp = ft_strsub(s, start, end - start);
	return (tmp);
}
