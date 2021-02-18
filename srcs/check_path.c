#include "lemin.h"

int				set_r_len(t_input *input, t_path *neu)
{
	t_room		**room;
	int			len;
	int			i;

	room = input->graph->data;
	i = 0;
	len = 0;
	while (i < neu->len)
	{
		if (room[neu->way[i]]->is_orig)
			len++;
		i++;
	}
	return (len);
}

int				check_path(t_input *input, t_path *neu)
{
	t_path		**path;
	t_vector	*ants_per_room;
	int			paths_count;
	int			old_res;
	int			new_res;

	ants_per_room = NULL;
	neu->real_len = set_r_len(input, neu);
	path = input->path_arr->data;
	set_r_len_all(path, input->path_arr->next);
	paths_count = count_paths(input);
	ants_per_room = set_ants_per_room(paths_count + 1, input->ants);
	old_res = calc_output(input, ants_per_room, 0);
}

void			sort_path(t_input *input)
{
	size_t	i;
	int		*arr;
	int		paths_count;
	size_t	j;
	t_path	**path;

	paths_count = count_paths(input);
	if (!(arr = (int *)malloc(sizeof(int) * paths_count * 2)))
		error(MEMORY);
	path = input->path_arr->data;
	j = 0;
	while (i < paths_count * 2)
	{
		while (j < input->path_arr->next && path[j]->status == 0)
			j++;
		arr[i + 1] = path[j]->id;
		arr[i] = path[j]->real_len;
		i += 2;
		j++;
	}
	i = 0;
	while (i + 2 < paths_count * 2)
	{
		j = i + 2;
		while (j < paths_count * 2)
		{
			if (arr[j] >= arr[i])
			{
				ft_swap(&arr[j], &arr[i]);
				ft_swap(&arr[j + 1], &arr[i + 1]);
			}
			j += 2;
		}
		i += 2;
	}

}