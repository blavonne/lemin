#include "lemin.h"

//static int	find_way(t_input *input)
//{
//	int		i;
//	t_room	**rooms;
//	int		*link;
//
//	i = 0;
//	link = room->near->data;
//	if (room->visited)
//		return (0);
//	while (i < room->near->next)
//	{
//		if (link[i]->is_end == 1)
//			return (1);
//		i++;
//	}
//	room->visited = 1;
//	i = 0;
//	while (i < room->ways->next)
//	{
//		if (find_way(ways[i]))
//			return (1);
//		i++;
//	}
//	return (0);
//}

static int	check_way_to_end(t_input *input, int start)
{
	t_room		**room;
	int			*index;
	int			i;

	i = 0;
	room = input->rooms->data;
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
}

void		check_input(t_input *input)
{
	if (!(check_way_to_end(input, input->start_id)))
		error(NOWAY);
}