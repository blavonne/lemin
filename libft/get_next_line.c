/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:30:40 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/23 17:21:10 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_buff	*find_fd(t_list **list, int fd)
{
	t_list	*tmp;
	t_buff	*data;

	tmp = *list;
	while (tmp)
	{
		if (((t_buff*)tmp->content)->fd == fd)
			return (tmp->content);
		tmp = tmp->next;
	}
	if (!(data = (t_buff*)malloc(sizeof(t_buff))))
		return (NULL);
	data->buff = NULL;
	data->fd = fd;
	if (!(tmp = ft_lstnew(data, sizeof(t_buff))))
	{
		free(data);
		return (NULL);
	}
	free(data);
	ft_lstadd(list, tmp);
	return ((*list)->content);
}

static int		ft_read_line(char **ostatok, int fd, char **line, size_t size)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	char	*str;

	size = 1;
	ft_bzero(buff, BUFF_SIZE + 1);
	while (size)
	{
		if ((tmp = ft_strchr(*ostatok, '\n')))
			*tmp++ = '\0';
		str = ft_strjoin(*line, *ostatok);
		free(*line);
		if (tmp && !(tmp = ft_strdup(tmp)))
			return (-1);
		free(*ostatok);
		if (!(*line = str))
			return (-1);
		if ((*ostatok = tmp))
			return (1);
		if (!(size = read(fd, buff, BUFF_SIZE)) && ft_strlen(*line))
			return (1);
		if (!(*ostatok = ft_strsub(buff, 0, size)))
			return (-1);
	}
	return (0);
}

static void		ft_del_one(void *cont, size_t size)
{
	free(((t_buff *)cont)->buff);
	free(cont);
	if (size)
		return ;
}

static void		ft_del_fd(t_list **head, int fd)
{
	t_list	*prev;
	t_list	*tmp;

	tmp = *head;
	if (((t_buff*)tmp->content)->fd == fd)
	{
		*head = (*head)->next;
		ft_lstdelone(&tmp, &ft_del_one);
		return ;
	}
	while (((t_buff *)(*head)->content)->fd != fd)
	{
		prev = *head;
		*head = (*head)->next;
	}
	prev->next = (*head)->next;
	ft_lstdelone(head, &ft_del_one);
	*head = tmp;
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_buff			*tmp;
	int				rd;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(tmp = find_fd(&head, fd)))
		return (-1);
	if (!tmp->buff)
		if (!(tmp->buff = ft_strnew(0)))
			return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if ((rd = ft_read_line(&(tmp->buff), fd, line, 0)) <= 0)
		ft_del_fd(&head, fd);
	return (rd);
}
