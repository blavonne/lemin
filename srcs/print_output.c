#include "lemin.h"

int				count_paths(t_input *input)
{
	size_t	i;
	size_t	active;
	t_path	**paths;

	i = 0;
	active = 0;
	paths = input->path_arr->data;
	while (i < input->path_arr->next)
	{
		if (paths[i]->status == 1)
			active++;
		i++;
	}
	return (active);
}

void			print_output(t_input *input)
{
	t_room	**rooms;
	t_path	**paths;

	rooms = input->graph->data;
	paths = input->path_arr->data;
	ant_management(input, rooms, paths);
}
