#include "lemin.h"

t_edge			*create_edge()
{
	t_edge		*neu;

	if (!(neu = (t_edge *)malloc(sizeof(t_edge))))
		error(MEMORY);
	ft_bzero(neu, sizeof(t_edge));
	neu->active = 1;
	neu->weight = 1;
	return (neu);
}

t_edge			*copy_edge_list(t_edge *src)
{
	t_edge	*neu;

	while (src)
	{
		neu = create_edge();
		ft_memcpy(neu, src, sizeof(t_edge));
		src = src->next;
	}
	return (neu);
}


/*
 * установит значение статуса активности
 */

void			set_active(t_edge *head, int from, int to, int value)
{
	t_edge		*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->from == from && ptr->to == to)
		{
			ptr->active = value;
			break ;
		}
		ptr = ptr->next;
	}
}

/*
 * установит значение веса
 */

void			set_weight(t_edge *head, int from, int to, int value)
{
	t_edge		*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->from == from && ptr->to == to)
		{
			ptr->weight = value;
			break ;
		}
		ptr = ptr->next;
	}
}

void			add_edge(t_edge **head, int from, int to)
{
	t_edge		*edge;
	t_edge		*ptr;

	edge = create_edge();
	edge->from = from;
	edge->to = to;
	if (!(*head))
		(*head) = edge;
	else
	{
		ptr = (*head);
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = edge;
	}
}
