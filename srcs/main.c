#include <stdio.h>
#include "lemin.h"

static void			init_input(t_input *input)
{
	ft_bzero(input, sizeof(t_input));
	input->end_id = -1;
	input->start_id = -1;
}

int			main(int argc, char **argv)
{
	t_input	input;

	init_input(&input);
	read_input(argc, argv, &input);
	check_input(&input);
	print_input(input);
//	set_links(&input);
	set_edge_default(&input);
//	dijkstra(&input);
//	bellman_ford(&input);
	suurbale(&input);
//	set_dist(&input);
//	set_path(&input);
	clean_vector(&input.graph);
	return 0;
}
