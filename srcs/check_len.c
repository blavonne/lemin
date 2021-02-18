#include "lemin.h"

t_vector		*set_ants_per_room(int paths, int ants)
{
	int			res;
	int			mid;
	t_vector	*neu;
	int			i;
	int			*arr;

	mid = ants / paths;
	res = mid * paths;
	neu = NULL;
	i = -1;
	while (++i < paths)
		push_in_vector(&neu, &mid, sizeof(int), INT);
	arr = neu->data;
	i = -1;
	while (res != ants && (size_t)++i < neu->next)
	{
		arr[i]++;
		res++;
	}
	return (neu);
}

/*
 * finds next min path len with of without replace
 */

int				find_min(t_input *input, int opt)
{
	size_t		i;
	int			min;
	int			min_index;
	t_path		**path;
	int			l;

	if (!input->path_arr->next)
		return (-1);
	i = -1;
	path = input->path_arr->data;
	min = 0;
	while (++i < input->path_arr->next)
	{
		if (path[i]->status == 1 && path[i]->marked == 0)
		{
			l = opt && path[i]->replace ? path[i]->replace : path[i]->real_len;
			if (min == 0 || l < min)
			{
				min = l;
				min_index = i;
			}
		}
	}
	min ? (path[min_index]->marked = 1) : 0;
	min && opt ? (path[min_index]->replace = 0) : 0;
	return (min);
}

int				still_not_marked(t_path **path, size_t len)
{
	size_t		i;

	i = 0;
	if (!len)
		return (-1);
	while (i < len)
	{
		if (path[i]->status == 1 && path[i]->marked == 0)
			return (1);
		i++;
	}
	return (0);
}

int				calc_output(t_input *input, t_vector *ants, int replace)
{
	int		*ant;
	size_t	i;
	t_path	**path;
	int		res;
	int		max;

	max = -1;
	path = input->path_arr->data;
	ant = ants->data;
	i = 0;
	while (still_not_marked(path, input->path_arr->next) == 1)
	{
		res = find_min(input, replace) + ant[i] - 1;
		i++;
		if (res > max)
			max = res;
	}
	reset_marked(path, input->path_arr->next);
	return (max);
}

/*
 * compares current output len with potential output len
 */

int				check_len(t_input *input, size_t i, size_t j, int *inter)
{
	int			paths_count;
	t_vector	*ants_per_room;
	int			old_res;
	int			new_res;
	t_path		**path;

	path = input->path_arr->data;
	ants_per_room = NULL;
	path[i]->replace = (inter[0] + 1) + (path[j]->len - (inter[2] + 1));
	path[j]->replace = (inter[3] + 1) + (path[i]->len - (inter[1] + 1));
	set_r_len_all(path, input->path_arr->next);
	set_priority(path, input->path_arr->next);
	paths_count = count_paths(input);
	ants_per_room = set_ants_per_room(paths_count, input->ants);
	old_res = calc_output(input, ants_per_room, 0);
	new_res = calc_output(input, ants_per_room, 1);
	new_res = (new_res >= old_res) ? 0 : 1;
	clean_vector(&ants_per_room, INT);
	return (new_res);
}
