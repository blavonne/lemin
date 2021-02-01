#include "lemin.h"

static int	check_way_to_end(t_input *input, int start)
{
	t_room		**room;
	int			*index;
	size_t		i;

	i = 0;
	room = input->room->data;
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

void		check_input(t_input *input)
{
	if (!(check_way_to_end(input, input->start_id)))
		error(NOWAY);
	reset_visited(input);
}
