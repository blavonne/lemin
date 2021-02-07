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

void			replace_edge_end(t_edge *edge_list, int value, int new_value)
{
	t_edge		*ptr;

	ptr = edge_list;
	while (ptr)
	{
		if (ptr->id == value)
			ptr->id = new_value;
		ptr = ptr->next;
	}
}

/*
 * установит значение веса и статуса активности
 */

void			set_active(t_input *input, int start, int end, int value)
{
	t_room		**room;
	t_edge		*ptr;

	room = input->graph->data;
	ptr = room[start]->edge_list;
	if (ptr)
	{
		while (ptr->id != end)
			ptr = ptr->next;
		ptr->active = value;
	}
}

void			set_weight(t_input *input, int start, int end, int value)
{
	t_room		**room;
	t_edge		*ptr;

	room = input->graph->data;
	ptr = room[start]->edge_list;
	if (ptr)
	{
		while (ptr->id != end)
			ptr = ptr->next;
		ptr->weight = value;
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

void			turn_off_edge()