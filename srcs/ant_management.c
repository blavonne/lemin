#include "lemin.h"

void		create_ant_arr(t_ant *ants, t_input *input, t_path **paths)
{
	int		ant_cnt;
	size_t	path_cnt;

	ant_cnt = 0;
	path_cnt = 0;
	while (ant_cnt < input->ants)
	{
		ants[ant_cnt].id = ant_cnt + 1;
		while (paths[path_cnt]->status == 0)
			path_cnt++;
		ants[ant_cnt].path = paths[path_cnt++];
		ants[ant_cnt].cur_step = 0;
		if (path_cnt == input->path_arr->next && ant_cnt < input->ants)
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

void	ant_management(t_input *input, t_room **rooms, t_path **paths)
{
	int		ant_cnt;
	size_t	path_cnt;
	t_ant	ants[input->ants];
	int		finished;

	ant_cnt = -1;
	path_cnt = 0;
	finished = 0;
	create_ant_arr(&ants[0], input, paths);
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
		}
	}
}
