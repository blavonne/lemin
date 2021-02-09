#include "lemin.h"

static int		check_way_to_end(t_input *input)
{
	t_room		**room;

	room = input->graph->data;
	if (room[input->end_id]->dist == INF)
		return (0);
	return (1);
}

int				count_paths(t_path **paths, t_input *input)
{
	size_t	i;
	size_t	active;

	i = 0;
	active = 0;
	while (i < input->path_arr->next)
	{
		if (paths[i]->status == 1)
			active++;
		i++;
	}
	return (active);
}

void			suurbale(t_input *input)
{
	int			i;
	t_room	**rooms;
	t_path	**paths;

	i = 1;
	while (i) //найдет все независимые пути
	{
		printf("==========suurbale %i============\n", i);
//		print_edge(input);
		reset_dist(input);
		reset_parent(input);
		bellman_ford(input);
		if (!check_way_to_end(input))
			break ;
		add_path(input);
		update_graph(input);
		print_path(input);
		i++;
	}
	frankenstein(input);
	print_path(input);
	rooms = input->graph->data;
	paths = input->path_arr->data;
	i = count_paths(paths, input);
	ant_management(input, rooms, paths, i);
}
