#include "lemin.h"

void			print_dist(t_room **room, int size)
{
	int		i;

	i = 0;
	printf("Bellman-Ford dist from start to other is:\n");
	while (i < size)
	{
		printf("room[%i] = %.f; ", i, room[i]->distance);
		i++;
	}
	printf("\n");
}

void			print_way(t_room **room, int end)
{
	t_room	*ptr;

	ptr = room[end];
	printf("Bellman-Ford way is: ");
	while (ptr->prev >= 0)
	{
		printf("%s ", ptr->name);
		ptr = room[ptr->prev];
	}
	printf("%s ", ptr->name);
	printf("\n\n");
}

void			reset_prev(t_room **room, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		room[i]->prev = -1;
		i++;
	}
}

void			bellman_ford(t_input *input)
{
	t_room	**room;
	t_room	**near;
	int		i;
	int		j;

	room = input->rooms->data;
	reset_dist(input);
	reset_prev(room, input->rooms->next);
	i = 0;
	while (i < input->rooms->next)
	{
		near = room[i]->ways->data;
		j = 0;
		while (j < room[i]->ways->next)
		{
			if (room[i]->distance > near[j]->distance + 1)
			{
				room[i]->distance = near[j]->distance + 1;
				room[i]->prev = near[j]->order;
			}
			j++;
		}
		i++;
	}
	print_dist(room, input->rooms->next);
	print_way(room, input->end_id);
}
