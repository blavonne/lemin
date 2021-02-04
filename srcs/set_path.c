#include "lemin.h"

int				set_path_len(t_input *input)
{
	t_room		**room;
	t_room		*ptr;
	int		len;

	len = 0;
	room = input->graph->data;
	ptr = room[input->end_id];
	while (ptr->is_start != 1)
	{
		len++;
		ptr = room[ptr->parent];
	}
	return (len);
}

void			set_path(t_input *input) // нужно создать вектор из структур s_path
{
	t_path		*path;
	t_room		**room;
	t_room		*ptr;
	int			i;

	path = create_path();
	path->len = set_path_len(input);
	if (!(path->step = (int *)malloc(sizeof(int) * path->len)))
		error(MEMORY);
	room = input->graph->data;
	ptr = room[input->end_id];
	i = path->len - 1;
	while (ptr->is_start != 1)
	{
		path->step[i] = ptr->parent;
		ptr = room[ptr->parent];
		i--;
	}
	if (!(push_in_vector(&input->path_arr, (void *)path, sizeof(t_path *),\
	POINTER)))
		error(MEMORY);
	path->id = (int)input->path_arr->next - 1;
}
