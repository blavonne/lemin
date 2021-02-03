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
	while (1) //найдет все независимые пути
	{
		reset_dist(input);
		reset_parent(input);
		bellman_ford(input);
		if (!check_way_to_end(input))
			break ;
		reset_link_and_weight(input);
		set_path(input); //пока не работает
	}
	printf("suurbale link-matrix:\n");
	print_matrix_i(input->link, input->graph->next);
	printf("suurbale weight-matrix:\n");
	print_matrix_i(input->weight, input->graph->next);
}
