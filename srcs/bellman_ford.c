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
 * если расстояние от старта до текущей комнаты больше, чем от старта до соседа
 * плюс вес сосед-текущая (при наличи связи сосед-текущая), то расстояние от
 * старта до текущей теперь равно расстоянию от старта до соседа плюс вес
 * ребра сосед-текущее
 */

void			bellman_ford2(t_input *input)
{
	t_room		**room;
	int			*index;
	size_t		i;
	size_t		j;

	room = input->graph->data;
	if (!input->weight)
	{
		input->weight = create_matrix_i(input->graph->next);
		feel_matrix_default_i(input, input->weight);
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
				if (room[index[j]]->distance != INF &&\
				input->link[index[j]][room[i]->id] &&\
				room[i]->distance > room[index[j]]->distance +\
				input->weight[index[j]][room[i]->id])
				{
					room[i]->distance = room[index[j]]->distance +\
					input->weight[index[j]][room[i]->id];
					room[i]->parent = index[j];
				}
			}
		}
	}
	print_dist(room, input->graph->next);
	print_way(room, input->end_id);
}

void			bellman_ford(t_input *input)
{
	size_t		h;
	size_t		w;
	t_room		**room;
	int			any;

	room = input->graph->data;
	set_matrix_default_i(input, &input->weight);
	while (1)
	{
		h = -1;
		any = 0;
		while (++h < input->graph->next)
		{
			w = -1;
			while (++w < input->graph->next)
			{
				if (input->link[h][w])
				{
					if (room[w]->distance > room[h]->distance +\
					input->weight[h][w])
					{
						room[w]->distance = room[h]->distance +\
						input->weight[h][w];
						room[w]->parent = h;
						room[h]->child = w;
						any = 1;
					}
				}
			}
		}
		if (!any)
			break ;
	}
	print_dist(room, input->graph->next);
	print_way(room, input->end_id);
}
