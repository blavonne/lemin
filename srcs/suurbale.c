#include "lemin.h"

static int		check_way_to_end(t_input *input)
{
	t_room		**room;

	room = input->graph->data;
	if (room[input->end_id]->dist == INF)
		return (0);
	return (1);
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
		print_edge(input);
		reset_dist(input);
		reset_parent(input);
		bellman_ford(input);
		if (!check_way_to_end(input))
			break ;
		add_path(input);
		update_graph(input);
		i++;
	}
	frankenstein(input);
	print_path(input);
	rooms = input->graph->data;
	paths = input->path_arr->data;
	ant_management(input, rooms, paths);
}
