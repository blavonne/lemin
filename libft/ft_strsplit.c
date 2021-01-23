/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:45:58 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/18 19:00:51 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *tmp, char c)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != c && (tmp[i + 1] == c || tmp[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_push_in_arr(char **arr, char *str, char c, int words)
{
	char	*word;
	char	*end;
	int		begin;
	int		k;

	k = 0;
	while (words--)
	{
		while (str[k] && str[k] == c)
			k++;
		begin = k;
		while (str[k] && str[k] != c)
			k++;
		end = &str[k];
		if (!(word = ft_strsub(str, begin, end - &str[begin])))
			return (0);
		if (!(*arr++ = ft_strdup(word)))
			return (0);
		free(word);
	}
	return (1);
}

static void	ft_clear_arr(char ***arr)
{
	size_t	i;

	if (!(*arr))
		return ;
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**buf;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words((char *)s, c);
	if (!(buf = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	if (ft_push_in_arr(buf, (char *)s, c, words))
		buf[words] = NULL;
	else
	{
		ft_clear_arr(&buf);
		return (NULL);
	}
	return (buf);
}
