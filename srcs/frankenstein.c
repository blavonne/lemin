#include "lemin.h"

/*
 * finds intersecting edges and feels int array[4] with their id in path.way
 */

static int		find_intersection(t_path *one, t_path *two, int *inter)
{
	int		i;
	int		j;

	i = -1;
	while (++i < one->len - 1)
	{
		j = two->len - 1;
		while (--j >= 0)
		{
			if (one->way[i] == two->way[j])
			{
				inter[0] = i++;
				inter[2] = j--;
				while(i + 1 < one->len && one->way[i] == one->way[i + 1])
					i++;
				while (j - 1 >= 0 && two->way[j] == two->way[j - 1])
					j--;
				while (i < one->len && j >= 0 && one->way[i] == two->way[j])
				{
					inter[1] = i++;
					inter[3] = j--;
				}
				return (1);
			}
		}
	}
	return (0);
}

static t_path	*glue_path(t_path *left, t_path *right, int l_to, int r_from)
{
	t_path		*zombie;

	zombie = create_path();
	zombie->len = (l_to + 1) + (right->len - (r_from + 1));
	if (!(zombie->way = (int *)malloc(sizeof(int) * zombie->len)))
		error(MEMORY);
	ft_memcpy(zombie->way, left->way, sizeof(int) * (l_to + 1));
	ft_memcpy(&zombie->way[l_to + 1], &right->way[r_from + 1],\
	sizeof(int) * (right->len - (r_from + 1)));
	return (zombie);
}

/*
 * after check potential output len with and without replace cross paths
 * makes two independent paths from two paths with intersection
 * returns 1 if two new paths were made and turns off old ways
 * returns 0 if remaster is not effective and turns off new way
 */

static int		path_remaster(t_input *input, size_t i, size_t j, int *inter)
{
	t_path		*one;
	t_path		*two;
	t_path		**path;

	if (check_len(input, i, j, inter))
	{
		path = input->path_arr->data;
		one = glue_path(path[i], path[j], inter[0], inter[2]);
		one->status = 1;
		two = glue_path(path[j], path[i], inter[3], inter[1]);
		two->status = 1;
		path[i]->status = 0;
		path[j]->status = 0;
		if (!(push_in_vector(&input->path_arr, one, sizeof(t_path *), PTR)))
			error(MEMORY);
		if (!(push_in_vector(&input->path_arr, two, sizeof(t_path *), PTR)))
			error(MEMORY);
		ft_memset(inter, -1, sizeof(int) * 4);
		return (1);
	}
	else
	{
		path[j]->status = 0;
		return (0);
	}
}

/*
 * find intersection between new path and older paths and try to divide
 * 2 path with intersection
 * returns 0 if potential output len is more that current and turns off new path
 * returns 1 if it is less, splits intersecting paths and turns off old ways
 * with intersection
 */

int				frankenstein(t_input *input)
{
	int		intersection[4];
	t_path	**path;
	size_t	i;
	size_t	j;

	if (input->path_arr->next > 1)
	{
		path = input->path_arr->data;
		ft_memset(intersection, -1, sizeof(int) * 4);
		j = input->path_arr->next - 1;
		i = -1;
		while (++i < j)
		{
			if (path[i]->status == 1)
			{
				if (find_intersection(path[i], path[j], intersection))
				{
					if (!path_remaster(input, i, j, intersection))
						return (0);
					path = input->path_arr->data;
				}
			}
		}
	}
	return (1);
}
