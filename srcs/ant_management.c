#include "lemin.h"

t_ant			*create_ant(int	id, t_path *path, int step)
{
	t_ant	*ant;

	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		error(MEMORY);
	ant->id = id;
	ant->path = path;
	ant->cur_step = step;
	return (ant);
}

void	make_step(t_ant *ant, t_room **rooms, int end_id)
{
	int		step_index;
	int		next_step;

	step_index = ant->path->way[ant->cur_step];
	next_step = ant->path->way[ant->cur_step + 1];
	if (ant->path->way[ant->cur_step])
	{
		if (rooms[step_index]->ant == NULL)
		{
			printf("%i %s ", ant->id, rooms[step_index]->name);
			rooms[step_index]->ant = ant;
			ant->cur_step++;
		}
		else
		{
			rooms[next_step]->ant = rooms[step_index]->ant;
			printf("%d - %s ", rooms[next_step]->ant->id, rooms[next_step]->name);
			rooms[next_step]->ant->cur_step++;
			rooms[step_index]->ant = NULL;
			make_step(ant, rooms, end_id);
		}
	}

}

void	ant_management(t_input *input, t_room **rooms, t_path **paths)
{
	size_t		i;
	size_t		j;
	t_ant	*ants[input->ants];
	int		finished;

	i = 0;
	j = 0;
	finished = 0;
	while (i < (size_t)input->ants)
	{
		ants[i] = create_ant(i + 1, paths[j], 0);
		i++;
		j++;
		if (j == input->path_arr->next && i < (size_t)input->ants)
			j = 0;
	}
	i = 0;
	j = 0;
	while (ants[i]->path->way[ants[i]->cur_step] != input->end_id || finished != input->ants)
	{
		if (ants[i]->path->way[ants[i]->cur_step] == input->end_id && ants[i]->id != -1)
		{
			finished++;
			ants[i]->id = -1;
			i++;
		}
		if (ants[i]->path->way[ants[i]->cur_step] != input->end_id)
		{
			make_step(ants[i], rooms, input->end_id);
			i++;
		}
		if (i == (size_t)input->ants)
			i = 0;
		j++;
		if (j == input->path_arr->next)
		{
			j = 0;
			write(1, "\n", 1);
		}
	}
}
