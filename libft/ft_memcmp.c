/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:51:26 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/12 21:28:37 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_ptr;
	const char	*s2_ptr;
	size_t		i;

	i = 0;
	s1_ptr = s1;
	s2_ptr = s2;
	while (i < n)
	{
		if (s1_ptr[i] == s2_ptr[i])
			i++;
		else
			return ((unsigned char)s1_ptr[i] - (unsigned char)s2_ptr[i]);
	}
	return (0);
}
