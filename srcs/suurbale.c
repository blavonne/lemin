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

	i = 0;
	while (i < 2) //найдет i независимых путей
	{
		reset_dist(input);
		reset_parent(input);
		bellman_ford(input);
		relink_and_reweight(input);
		set_path(input);
//		update_graph(input);
		if (!check_way_to_end(input))
			break ;
		i++;
	}
	print_path(input);
}
