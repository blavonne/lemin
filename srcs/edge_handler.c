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

/*
 * начиная с финиша, устанавливает значение -1 в матрице веса между комнатой
 * и ее родителем (на первой итерации между финишем и предшественницей);
 * обнуляет связь родитель -> комната,
 * т.е. было room <-> parent, стало room -> parent
 * было weight[room][parent] = 1, стало weight[room][parent] = -1
 * (построение обратного ребра)
 */

void			reverse_edges(t_input *input)
{
	t_room		**room;
	t_room		*ptr;

	room = input->graph->data;
	ptr = room[input->end_id];
	while (ptr->is_start != 1 && ptr->parent != NONE)
	{
		set_active(input->edge_list, ptr->parent, ptr->id, 0);
		set_active(input->edge_list, ptr->id, ptr->parent, 1);
		set_weight(input->edge_list, ptr->id, ptr->parent, -1);
		ptr = room[ptr->parent];
	}
}
