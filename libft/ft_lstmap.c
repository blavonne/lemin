/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:56:09 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/17 22:00:18 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = f(lst);
	head = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		list = list->next;
	}
	return (head);
}
