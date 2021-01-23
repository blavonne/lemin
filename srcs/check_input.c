#include "lemin.h"

static int	find_way(t_room *room)
{
	int		i;
	t_room	**ways;

	i = 0;
	ways = room->ways->data;
	if (room->visited)
		return (0);
	while (i < room->ways->next)
	{
		if (ways[i]->is_end == 1)
			return (1);
		i++;
	}
	room->visited = 1;
	i = 0;
	while (i < room->ways->next)
	{
		if (find_way(ways[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	check_way_to_end(t_vector *v)
{
	t_room		**room;
	int			i;

	i = 0;
	room = v->data;
	while (i < v->next)
	{
		if (room[i]->is_start == 1)
			break ;
		i++;
	}
	if (!room[i]->ways || !find_way(room[i]))
		error(NOWAY);
}

void		check_input(t_input *input)
{
	check_way_to_end(input->rooms);
}