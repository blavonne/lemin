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
	while (ptr->parent >= 0)
	{
		printf("%s ", ptr->name);
		ptr = room[ptr->parent];
	}
	printf("%s ", ptr->name);
	printf("\n\n");
}

/*
 * если расстояние от старта до текущей комнаты больше, чем от соседа до
 * текущей, то расстояние от старта до текущей теперь равно расстоянию
 * от старта до соседа плюс вес ребра сосед-текущее
 */

void			bellman_ford(t_input *input)
{
	t_room		**room;
	int			*index;
	size_t		i;
	size_t		j;

	room = input->graph->data;
	if (!input->weight)
	{
		input->weight = create_matrix_i(input->graph->next);
		feel_matrix_default(input, input->weight);
	}
	i = -1;
	while (++i < input->graph->next)
	{
		if (room[i]->near)
		{
			index = room[i]->near->data;
			j = -1;
			while (++j < room[i]->near->next)
			{
				if (input->link[index[j]][room[i]->id] && \
				room[i]->distance > room[index[j]]->distance +\
				input->weight[room[i]->id][index[j]])
				{
					room[i]->distance = room[index[j]]->distance +\
					input->weight[room[i]->id][index[j]];
					room[i]->parent = room[index[j]]->id;
				}
			}
		}
	}
	print_dist(room, input->graph->next);
	print_way(room, input->end_id);
}
