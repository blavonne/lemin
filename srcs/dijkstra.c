#include "lemin.h"

static void	set_weight(t_input *input)
{
	t_room	**room;
	int		i;

	i = 0;
	room = input->rooms->data;
	while (i < input->rooms->next)
	{
		if (room[i]->is_start)
			room[i]->weight = 0;
		else
			room[i]->weight = INF;
		i++;
	}
}

static int	value_neighbors(t_room *start, t_input *input)
{
	t_room	**room;
	int		*index;
	int		i;

	i = 0;
	if (start->visited == 0)
	{
		room = input->rooms->data;
		index = start->near->data;
		while (i < start->near->next)
		{
			if (room[index[i]]->weight == INF)
			{
				room[index[i]]->weight = 1;
				room[index[i]]->prev = start->order;
			}
			else
				if (room[index[i]]->weight > start->weight + 1)
				{
					room[index[i]]->weight = start->weight + 1;
					room[index[i]]->prev = start->order;
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
	return (0);
}

int 		find_end(t_input *input)
{
	t_room	**room;
	int		i;

	i = 0;
	room = input->rooms->data;
	while (i < input->rooms->next)
	{
		if (room[i]->is_end == 1)
			return (i);
		i++;
	}
	return (0);
}

void		print_shortest(t_input *input, int end)
{
	t_room	**room;
	t_room	*ptr;

	room = input->rooms->data;
	printf("End is room %s.\n", room[end]->name);
	printf("Way is:\n");
	ptr = room[end];
	while (1)
	{
		printf("%s ", ptr->name);
		ptr = room[ptr->prev];
		if (ptr->is_start)
			break ;
	}
	printf("%s\n", ptr->name);
}

void		dijkstra(t_input *input)
{
	t_room	**room;
	int		i;

	i = 0;
	room = input->rooms->data;
	set_weight(input);
	while (i < input->rooms->next)
	{
		if (room[i]->is_start)
			break ;
		i++;
	}
	value_neighbors(room[i], input);
	i = find_end(input);
	print_shortest(input, i);
}