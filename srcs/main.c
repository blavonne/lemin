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
	suurbale(&input);
	print_output(&input);
	clean_vector(&input.graph, ROOM);
	return 0;
}
