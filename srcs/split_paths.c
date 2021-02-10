#include "lemin.h"

/*
 * replaces copy_id in path.way by orig_id
 */

static void		replace_copy_orig(t_input *input)
{
	t_path		**path;
	size_t		i;
	int			*way;
	size_t		j;
	t_room		**r;

	path = input->path_arr->data;
	r = input->graph->data;
	i = 0;
	while (i < input->path_arr->next)
	{
		j = 0;
		way = path[i]->way;
		while (j + 1 < (size_t)path[i]->len)
		{
			if (r[way[j]]->is_copy == 1)
				way[j] = r[way[j]]->orig_id;
			j++;
		}
		i++;
	}
}

/*
 * tries to split ways with edge-intersection
 * returns 0 if it is failed
 * returns 1 if it is ok
 */

int				split_paths(t_input *input)
{
	replace_copy_orig(input);
	if (!frankenstein(input))
		return (0);
	return (1);
}
