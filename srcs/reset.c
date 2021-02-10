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
		room[i]->child = NONE;
		i++;
	}
}

void			reset_marked(t_path **path, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (path[i]->status == 1)
			path[i]->marked = 0;
		i++;
	}
}
