/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:22:33 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/17 22:32:48 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*s_f;

	i = 0;
	if (!s)
		return (NULL);
	s_f = ft_strnew(ft_strlen(s));
	while (i < ft_strlen(s) && s_f)
	{
		s_f[i] = f(i, s[i]);
		i++;
	}
	return (s_f);
}
