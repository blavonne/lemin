#include "lemin.h"

/*
 * установит дистанцию от старта до остальных комнат на INF
 * и на 0 на самом старте
 */

void			reset_dist(t_input *input)
{
	t_room	**room;
	size_t	i;

	i = 0;
	room = input->graph->data;
	while (i < input->graph->next)
	{
		room[i]->dist = INF;
		i++;
	}
	room[input->start_id]->dist = 0;
}

/*
 * установит значение индекса родителя для каждой комнаты на -1
 */

void			reset_parent(t_input *input)
{
	t_room	**room;
	size_t	i;

	i = 0;
	room = input->graph->data;
	while (i < input->graph->next)
	{
		room[i]->parent = NONE;
		i++;
	}
}

/*
 * установит флаг посещенности каждой комнаты на 0
 * нужна для определения, есть ли путь к финишу, можно переложить
 * ответственность на беллмана-форда в первой итерации и убрать
 */

void			reset_visited(t_input *input)
{
	t_room		**room;
	size_t		i;

	i = 0;
	room = input->graph->data;
	while (i < input->graph->next)
	{
		room[i]->visited = 0;
		i++;
	}
}

static void		set_link(t_input *input, int parent, int child, int value)
{
	t_room		**room;
	t_edge		*ptr;

	room = input->graph->data;
	ptr = room[parent]->edge_list;
	if (ptr)
	{
		while (ptr && ptr->id != child)
			ptr = ptr->next;
		ptr->active = value;
	}
}

static void		set_weight(t_input *input, int parent, int child, int value)
{
	t_room		**room;
	t_edge		*ptr;

	room = input->graph->data;
	ptr = room[parent]->edge_list;
	if (ptr)
	{
		while (ptr->id != child)
			ptr = ptr->next;
		ptr->weight = value;
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

void			relink_and_reweight(t_input *input)
{
	t_room		**room;
	t_room		*ptr;

	room = input->graph->data;
	ptr = room[input->end_id];
	while (ptr->is_start != 1 && ptr->parent != NONE)
	{
		set_link(input, ptr->parent, ptr->id, 0);
		set_weight(input, ptr->id, ptr->parent, -1);
		ptr = room[ptr->parent];
	}
}
