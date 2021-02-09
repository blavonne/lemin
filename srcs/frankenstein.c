#include "lemin.h"

/*
 * заменит id клонов в пути на id оригиналов
 */

void			remove_repeat(t_input *input)
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
		while (j + 1 < path[i]->len)
		{
			if (r[way[j]]->is_copy == 1)
				way[j] = r[way[j]]->orig_id;
			j++;
		}
		i++;
	}
}

void			find_intersection(t_path *one, t_path *two, int *inter)
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
				return ;
			}
		}
	}
}

void			path_remaster(t_input *input, size_t i, size_t j, int *inter)
{
	t_path		*one;
	t_path		*two;
	t_path		**path;

	one = create_path();
	path = input->path_arr->data;
	one->len = (inter[0] + 1) + (path[j]->len - (inter[2] + 1));
	if (!(one->way = (int *)malloc(sizeof(int) * one->len)))
		error(MEMORY);
	ft_memcpy(one->way, path[i]->way, sizeof(int) * (inter[0] + 1));
	ft_memcpy(&one->way[inter[0] + 1], &path[j]->way[inter[2] + 1],\
	sizeof(int) * (path[j]->len - (inter[2] + 1)));
	if (!(push_in_vector(&input->path_arr, one, sizeof(t_path *), PTR)))
		error(MEMORY);
	one->status = 1;
	two = create_path();
	two->len = (inter[3] + 1) + (path[i]->len - (inter[1] + 1));
	if (!(two->way = (int *)malloc(sizeof(int) * two->len)))
		error(MEMORY);
	ft_memcpy(two->way, path[j]->way, sizeof(int) * (inter[3] + 1));
	ft_memcpy(&two->way[inter[3] + 1], &path[i]->way[inter[1] + 1],\
	sizeof(int) * path[i]->len - (inter[1] + 1));
	if (!(push_in_vector(&input->path_arr, two, sizeof(t_path *), PTR)))
		error(MEMORY);
	two->status = 1;
}

void			divide_intersection(t_input *input)
{
	int		intersection[4];
	t_path	**path;
	size_t	i;
	size_t	j;
	size_t	len;

	path = input->path_arr->data;
	len = input->path_arr->next;
	i = -1;
	ft_memset(intersection, -1, sizeof(int) * 4);
	while (++i + 1 < len)
	{
		j = i;
		while (path[i]->status == 1 && ++j && j < len)
		{
			if (path[j]->status == 1)
			{
				find_intersection(path[i], path[j], intersection);
				if (intersection[0] != -1)
				{
					path_remaster(input, i, j, intersection);
					path[i]->status = 0;
					path[j]->status = 0;
					ft_memset(intersection, -1, sizeof(int) * 4);
				}
			}
		}
	}
}

void			frankenstein(t_input *input)
{
	remove_repeat(input);
	divide_intersection(input);
}