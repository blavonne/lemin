#include "lemin.h"

static void	value_neighbors(t_room *start, t_input *input)
{
	t_room	**room;
	int		*index;
	size_t	i;

	i = 0;
	if (start->visited == 0)
	{
		room = input->room->data;
		index = start->near->data;
		while (i < start->near->next)
		{
			if (room[index[i]]->distance == INF)
			{
				room[index[i]]->distance = 1;
				room[index[i]]->parent = start->order;
			}
			else
				if (room[index[i]]->distance > start->distance + 1)
				{
					room[index[i]]->distance = start->distance + 1;
					room[index[i]]->parent = start->order;
				}
			i++;
		}
		start->visited = 1;
		i = 0;
		while (i < start->near->next)
		{
			value_neighbors(room[index[i]], input);
			i++;
		}
	}
}

void		print_shortest(t_input *input, int end)
{
	t_room	**room;
	t_room	*ptr;

	room = input->room->data;
	printf("Dijkstra way is: ");
	ptr = room[end];
	while (1)
	{
		printf("%s ", ptr->name);
		ptr = room[ptr->parent];
		if (ptr->is_start)
			break ;
	}
	printf("%s", ptr->name);
	printf("\n\n");
}

void		dijkstra(t_input *input)
{
	t_room	**room;
	size_t	i;

	i = 0;
	room = input->room->data;
	reset_dist(input);
	while (i < input->room->next)
	{
		if (room[i]->is_start)
			break ;
		i++;
	}
	value_neighbors(room[i], input);
	print_shortest(input, input->end_id);
}