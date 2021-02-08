#include "lemin.h"

t_ant			create_ant(int	id, t_path *path, int step)
{
	t_ant	ant;

	ant.id = id;
	ant.path = path;
	ant.cur_step = step;
	return (ant);
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
			fflush(stdout);
			rooms[step_index]->ant = ant;
			ant->cur_step++;
			if (rooms[step_index]->is_end == 1)
			{
				(*finished)++;
				ant->id = -1;
			}
		}
		else
		{
			if (rooms[step_index]->is_end != 1)
			{
				make_step(rooms[step_index]->ant, rooms, finished);
			}
			rooms[step_index]->ant = NULL;
			make_step(ant, rooms, finished);
		}
	}
}

void	ant_management(t_input *input, t_room **rooms, t_path **paths)
{
	size_t		i;
	size_t		j;
	t_ant	ants[input->ants];
	int		finished;

	i = 0;
	j = 0;
	finished = 0;
	while (i < (size_t)input->ants)
	{
		ants[i] = create_ant(i, paths[j++], 0);
		if (j == input->path_arr->next && i < (size_t)input->ants)
			j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (finished != input->ants)
	{
		if (i == (size_t)input->ants)
			i = 0;
		if (ants[i].id != -1 && ants[i].path->way[ants[i].cur_step] == input->end_id)
		{
			make_step(&ants[i], rooms, &finished);
			ants[i].id = -1;
			i++;
			continue ;
		}
		if (ants[i].id == -1)
		{
			i++;
			continue;
		}
		if (ants[i].path->way[ants[i].cur_step] != input->end_id)
		{
			make_step(&ants[i], rooms, &finished);
			i++;
		}
		j++;
		if (j == input->path_arr->next)
		{
			j = 0;
			write(1, "\n", 1);
		}
	}
	write(1, "\n", 1);
}
