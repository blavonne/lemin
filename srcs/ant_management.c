#include "lemin.h"

void		create_ant_arr(t_ant *ants, t_input *input, t_path **paths)
{
	int		ant_cnt;
	size_t	path_cnt;

	ant_cnt = 0;
	path_cnt = 0;
	while (ant_cnt < input->ants)
	{
		ants[ant_cnt].id = ant_cnt;
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
	int		next_step;

	if (ant->cur_step < ant->path->len)
	{
		step_index = ant->path->way[ant->cur_step];
		next_step = ant->path->way[ant->cur_step + 1];
		if (rooms[step_index]->ant == NULL)
		{
			printf("L%d-%s ", ant->id, rooms[step_index]->name);
			rooms[step_index]->ant = ant;
			ant->cur_step++;
			if (rooms[step_index]->is_end == 1 && ++(*finished))
				ant->id = -1;
		}
		else
		{
			rooms[step_index]->is_end != 1 ? make_step(rooms[step_index]->ant, rooms, finished) : 0;
			rooms[step_index]->ant = NULL;
			make_step(ant, rooms, finished);
		}
	}
}

void	ant_management(t_input *input, t_room **rooms, t_path **paths, size_t active)
{
	size_t	ant_cnt;
	size_t	path_cnt;
	t_ant	ants[input->ants];
	int		finished;

	ant_cnt = -1;
	path_cnt = 0;
	finished = 0;
	create_ant_arr(&ants[0], input, paths);
	while (finished != input->ants && ++ant_cnt >= 0)
	{
		if (ant_cnt == (size_t)input->ants)
		{
			ant_cnt = 0;
			if (path_cnt != 0)
				printf("\n");
		}
		if (ants[ant_cnt].id == -1)
			continue;
		if (ants[ant_cnt].path->way[ants[ant_cnt].cur_step] == input->end_id)
		{
			make_step(&ants[ant_cnt], rooms, &finished);
			continue ;
		}
		make_step(&ants[ant_cnt], rooms, &finished);
		if (++path_cnt == active)
		{
			path_cnt = 0;
			printf("\n");
		}
	}
	printf("\n");
}
