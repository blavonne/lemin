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
 * установит значение веса и статуса активности на 1
 */

void			set_edge(t_room *room, int edge_id, int weight, int active)
{
	t_edge	*ptr;

	ptr = room->edge_list;
	while (ptr)
	{
		if (ptr->id == edge_id)
		{
			ptr->weight = weight;
			ptr->active = active;
		}
		ptr = ptr->next;
	}
}

void			add_edge(t_input *input, int from, int to)
{
	t_room		**room;
	t_edge		*edge;
	t_edge		*ptr;

	room = input->graph->data;
	edge = create_edge();
	edge->id = to;
	if (!room[from]->edge_list)
		room[from]->edge_list = edge;
	else
	{
		ptr = room[from]->edge_list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = edge;
	}
}
