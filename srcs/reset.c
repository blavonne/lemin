#include "lemin.h"

void			reset_dist(t_input *input)
{
	t_room	**room;
	size_t	i;

	i = 0;
	room = input->room->data;
	while (i < input->room->next)
	{
		room[i]->distance = INF;
		i++;
	}
	room[input->start_id]->distance = 0;
}

void			reset_parent(t_input *input)
{
	t_room	**room;
	size_t	i;

	i = 0;
	room = input->room->data;
	while (i < input->room->next)
	{
		room[i]->parent = -1;
		i++;
	}
}

void			reset_visited(t_input *input)
{
	t_room		**room;
	size_t		i;

	i = 0;
	room = input->room->data;
	while (i < input->room->next)
	{
		room[i]->visited = 0;
		i++;
	}
}

void			reset_link_and_weight(t_input *input)
{
	t_room		**room;
	t_room		*ptr;

	room = input->room->data;
	ptr = room[input->end_id];
	while (ptr->is_start != 1)
	{
		input->weight[ptr->order][ptr->parent] = -1;
		input->link[ptr->parent][ptr->order] = 0;
		ptr = room[ptr->parent];
	}
}
