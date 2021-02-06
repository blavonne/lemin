#include "lemin.h"

/*
 * установит значение веса и статуса активности на 1
 */

void			set_edge_default(t_input *input)
{
	t_room		**room;
	t_edge		*ptr;
	size_t		i;

	i = 0;
	room = input->graph->data;
	while (i < input->graph->next)
	{
		ptr = room[i]->edge_list;
		while (ptr)
		{
			ptr->weight = 1;
			ptr->active = 1;
			ptr = ptr->next;
		}
		i++;
	}
}

t_edge			*create_edge()
{
	t_edge		*neu;

	if (!(neu = (t_edge *)malloc(sizeof(t_edge))))
		error(MEMORY);
	ft_bzero(neu, sizeof(t_edge));
	return (neu);
}

void			add_edge(t_edge **head, t_edge *neu)
{
	t_edge		*ptr;

	if (!(*head))
		(*head) = neu;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = neu;
	}
}

void			set_edge(t_input *input, int from, int to)
{
	t_room		**room;
	t_edge		*edge;

	room = input->graph->data;
	edge = create_edge();
	edge->id = to;
	add_edge(&room[from]->edge_list, edge);
}
