#include "lemin.h"

t_vector 		*set_steps(t_input *input)
{
	t_vector	*step;
	t_room		**room;
	t_room		*ptr;

	room = input->graph->data;
	ptr = room[input->end_id];
	step = NULL;
	while (ptr->is_start != 1)
	{
		if (!(push_in_vector(&step, &ptr->id, sizeof(int), INT)))
			error(MEMORY);
		ptr = room[ptr->parent];
	}
	return (step);
}

void			set_path(t_input *input) // нужно создать вектор из структур s_path
{
	t_vector	*step;

	step = set_steps(input);
	if (!(push_in_vector(&input->path, (void *)step, sizeof(t_vector *),\
	POINTER)))
		error(MEMORY);
}
