#include "lemin.h"

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

void			print_output(t_input *input)
{
	t_room	**rooms;
	t_path	**paths;
	int		i;

	rooms = input->graph->data;
	paths = input->path_arr->data;
	i = count_paths(paths, input);
	ant_management(input, rooms, paths);
}
