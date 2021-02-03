#include "lemin.h"

static int	check_way_to_end(t_input *input, int start)
{
	t_room		**room;
	int			*index;
	size_t		i;

	i = 0;
	room = input->graph->data;
	if (!room[start]->near)
		return (0);
	index = room[start]->near->data;
	if (room[start]->visited)
		return (0);
	while (i < room[start]->near->next)
	{
		if (room[index[i]]->is_end)
			return (1);
		i++;
	}
	room[start]->visited = 1;
	i = 0;
	while (i < room[start]->near->next)
	{
		if (check_way_to_end(input, index[i]))
			return (1);
		i++;
	}
	return (0);
}

int			check_dups(t_input *input)
{
	size_t	i;
	size_t	j;
	t_room	**room;
	char	*name;
	int		*coords;

	i = 0;
	room = input->graph->data;
	while (i < input->graph->next)
	{
		coords = room[i]->coords;
		name = room[i]->name;
		j = i;
		while (++j < input->graph->next)
		{
			if (ft_strequ(name, room[j]->name) || (coords[0] ==\
			room[j]->coords[0] && coords[1] == room[j]->coords[1]))
				return (0);
		}
		i++;
	}
	return (1);
}

void		check_input(t_input *input)
{
	if (!(check_dups(input)))
		error(DUPS);
	if (!(check_way_to_end(input, input->start_id)))
		error(NOWAY);
	reset_visited(input);
}
