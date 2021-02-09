#include "lemin.h"

void		create_ant_arr(t_ant *ants, t_input *input, t_path **paths)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < input->ants)
	{
		ants[i].id = i;
		while (paths[j]->status == 0)
			j++;
		ants[i].path = paths[j++];
		ants[i].cur_step = 0;
		if (j == input->path_arr->next && i < input->ants)
			j = 0;
		i++;
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
	size_t	i;
	size_t	j;
	t_ant	ants[input->ants];
	int		finished;

	i = -1;
	j = 0;
	finished = 0;
	create_ant_arr(&ants[0], input, paths);
	while (finished != input->ants && ++i >= 0)
	{
		i = (i == (size_t)input->ants) ? 0 : i;
		if (ants[i].id == -1)
			continue;
		if (ants[i].path->way[ants[i].cur_step] == input->end_id)
		{
			make_step(&ants[i], rooms, &finished);
			continue ;
		}
		make_step(&ants[i], rooms, &finished);
		j++;
		if (j == active)
		{
			j = 0;
			printf("\n");
		}
	}
	printf("\n");
}
