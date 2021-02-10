#include "lemin.h"

void		calc_ants_per_path(t_path *sorted[], int ants, int active)
{
	int		i;
	int		j;
	float	sum;
	int		copy;

	i = 0;
	sum = 0;
	j = -1;
	copy = ants;
	while (++j < active)
	{
		while (i < active)
			sum += (float)sorted[i++]->len / sorted[active - 1]->len;
		i = j;
		sorted[i]->ants_num = ants / sum;
		ants -= sorted[i++]->ants_num;
		sum = 0;
	}
	i = 0;
	while (i < active)
		sum += sorted[i++]->ants_num;
	i = 0;
	if (sum < copy)
		while (sum++ < copy)
			sorted[i++]->ants_num++;
}

void		sort_and_copy(t_path *sorted[], t_input *input, t_path **paths, int active)
{
	size_t	path_cnt;
	int		i;
	int		min;

	path_cnt = 0;
	i = 0;
	min = 0;
	while (i < active)
	{
		while (path_cnt < input->path_arr->next)
		{
			if (paths[path_cnt]->status == 1 && paths[path_cnt]->priority == min)
				break ;
			path_cnt++;
		}
		if (path_cnt < input->path_arr->next && paths[path_cnt]->priority == min)
			sorted[i++] = paths[path_cnt++];
		else
		{
			min -= 1;
			path_cnt = 0;
		}
	}
}

void		create_ant_arr(t_ant *ants, t_input *input, t_path **paths, int active)
{
	int		ant_cnt;
	size_t	path_cnt;
	t_path	*sorted[active];

	ant_cnt = 0;
	path_cnt = 0;
	sort_and_copy(sorted, input, paths, active);
	calc_ants_per_path(sorted, input->ants, active);
	path_cnt = 0;
	while (ant_cnt < input->ants)
	{
		ants[ant_cnt].id = ant_cnt + 1;
		if (sorted[path_cnt]->ants_num <= 0)
		{
			path_cnt = 0;
			while (sorted[path_cnt]->ants_num <= 0)
				path_cnt++;
		}
		ants[ant_cnt].path = sorted[path_cnt];
		sorted[path_cnt++]->ants_num -= 1;
		ants[ant_cnt].cur_step = 0;
		if (path_cnt == (size_t)active && ant_cnt < input->ants)
			path_cnt = 0;
		ant_cnt++;
	}
}

void	make_step(t_ant *ant, t_room **rooms, int *finished)
{
	int		step_index;

	if (ant->cur_step < ant->path->len)
	{
		step_index = ant->path->way[ant->cur_step];
		if (rooms[step_index]->ant == NULL || rooms[step_index]->is_end == 1)
		{
			printf("L%d-%s ", ant->id, rooms[step_index]->name);
			rooms[step_index]->ant = ant;
			if (ant->cur_step - 1 >= 0)
				rooms[ant->path->way[ant->cur_step - 1]]->ant = NULL;
			if (rooms[step_index]->is_end == 1 && ++(*finished))
				ant->id = -1;
			if (ant->id != -1)
				ant->cur_step++;
		}
	}
}

void	ant_management(t_input *input, t_room **rooms, t_path **paths, int active)
{
	int		ant_cnt;
	t_ant	ants[input->ants];
	int		finished;
	int		str;

	ant_cnt = -1;
	finished = 0;
	str = 0;
	create_ant_arr(&ants[0], input, paths, active);
	while (finished != input->ants && ++ant_cnt >= 0)
	{
		if (rooms[ants[ant_cnt].path->way[ants[ant_cnt].cur_step]]->ant == NULL \
		|| rooms[ants[ant_cnt].path->way[ants[ant_cnt].cur_step]]->is_end == 1)
			if (ants[ant_cnt].id != -1)
				make_step(&ants[ant_cnt], rooms, &finished);
		if (ant_cnt == input->ants - 1)
		{
			ant_cnt = -1;
			printf("\n");
			str++;
		}
	}
	printf("Total - %d lines\n", str);
}
