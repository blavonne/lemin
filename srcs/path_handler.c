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

t_path			*collect_path(t_input *input) // нужно создать вектор из структур s_path
{
	t_path		*path;
	t_room		**room;
	t_room		*ptr;
	int			i;
	int			len;

	len = set_path_len(input);
	if (len)
	{
		path = create_path();
		path->len = len;
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
		return (path);
	}
	return (NULL);
}

void			add_path(t_input *input, t_path *neu)
{
	if (!(push_in_vector(&input->path_arr, (void *)neu, sizeof(t_path *),\
		PTR)))
		error(MEMORY);
	neu->id = (int)input->path_arr->next - 1;
}

void			set_priority(t_path **path, size_t len)
{
	size_t		i;
	int			min;

	i = 0;
	if (len)
	{
		min = path[0]->real_len;
		while (++i < len)
		{
			if (path[i]->status == 1 && path[i]->real_len < min)
				min = path[i]->real_len;
		}
		i = -1;
		while (++i < len)
			if (path[i]->status == 1)
				path[i]->priority = min - path[i]->real_len;
	}
}

/*
 * evaluates real way len without repeats
 */

void			set_r_len_all(t_path **path, size_t len)
{
	size_t		i;
	int			j;
	int			repeat;

	i = 0;
	while (i < len)
	{
		j = 0;
		repeat = 0;
		if (path[i]->status == 1 && path[i]->real_len == 0)
		{
			while (j + 1 < path[i]->len)
			{
				if (path[i]->way[j] == path[i]->way[j + 1])
					repeat++;
				j++;
			}
			path[i]->real_len = path[i]->len - repeat;
			i++;
		}
	}
}
