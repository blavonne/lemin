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

	i = 1;
	while (i) //найдет все независимые пути
	{
//		print_edge(input);
		reset_dist(input);
		reset_parent(input);
		bellman_ford(input);
		if (!check_way_to_end(input))
			break ;
		add_path(input);
		update_graph(input);
		printf("==========suurbale %i============\n", i);
		print_path(input);
		printf("\n");
		i++;
	}
	frankenstein(input);
	printf("======suurbale after glue=======\n");
	print_path(input);
}
