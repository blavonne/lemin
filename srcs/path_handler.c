#include "lemin.h"

t_path			*create_path(void)
{
	t_path		*obj;

	if (!(obj = (t_path *)malloc(sizeof(t_path))))
		error(MEMORY);
	ft_bzero(obj, sizeof(t_path));
	return (obj);
}

int				set_path_len(t_input *input)
{
	t_room		**room;
	t_room		*ptr;
	int		len;

	len = 0;
	room = input->graph->data;
	ptr = room[input->end_id];
	while (ptr->is_start != 1 && ptr->parent != NONE)
	{
		len++;
		ptr = room[ptr->parent];
	}
	return (len);
}

void			add_path(t_input *input) // нужно создать вектор из структур s_path
{
	t_path		*path;
	t_room		**room;
	t_room		*ptr;
	int			i;

	path = create_path();
	path->len = set_path_len(input);
	if (path->len)
	{
		if (!(path->way = (int *)malloc(sizeof(int) * path->len)))
			error(MEMORY);
		room = input->graph->data;
		ptr = room[input->end_id];
		i = path->len - 1;
		while (ptr->is_start != 1 && ptr->parent != NONE)
		{
			path->way[i] = ptr->id;
			ptr = room[ptr->parent];
			i--;
		}
		if (!(push_in_vector(&input->path_arr, (void *)path, sizeof(t_path *),\
		PTR)))
			error(MEMORY);
		path->id = (int)input->path_arr->next - 1;
	}
}
