#include "lemin.h"

static int		check_way_to_end(t_input *input)
{
	t_room		**room;

	room = input->graph->data;
	if (room[input->end_id]->distance == INF)
		return (0);
	return (1);
}

void			suurbale(t_input *input)
{
	int			i;

	i = 0;
	while (i < 2) //найдет i независимых пути
	{
		reset_dist(input);
		reset_parent(input);
		bellman_ford(input);
		relink_and_reweight(input);
		set_path(input);
		printf("suurbale link-matrix iter %i:\n", i);
		print_matrix_i(input->link, input->graph->next);
		printf("suurbale weight-matrix iter %i:\n", i);
		print_matrix_i(input->weight, input->graph->next);
		if (!check_way_to_end(input))
			break ;
		i++;
	}
	print_path(input);
}
