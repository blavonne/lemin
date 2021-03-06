#include "lemin.h"

void		print_vector(t_vector *vector)
{
	size_t	i;
	t_room	**room;
	int		*related;
	size_t	j;

	i = 0;
	room = vector->data;
	while (i < vector->next)
	{
		j = 0;
		printf("Name №%i: %s (%i, %i)\n", room[i]->id, room[i]->name,\
		room[i]->coords[0], room[i]->coords[1]);
		if (room[i]->near)
		{
			printf("Related with: ");
			related = room[i]->near->data;
			while (j < room[i]->near->next)
			{
				printf("%s ", room[related[j]]->name);
				j++;
			}
			printf("\n");
		}
		if (room[i]->near)
		{
			printf("Related with: ");
			size_t	m;
			int		*ptr;

			m = 0;
			ptr = room[i]->near->data;
			while (m < room[i]->near->next)
			{
				printf("room[%i] ", ptr[m]);
				m++;
			}
			printf("\n");
		}
		printf("\n");
		i++;
	}
}

void		print_input(t_input input)
{
	printf("Ants: %i\n", input.ants);
	printf("Rooms:\n");
	print_vector(input.graph);
}

void			print_dist(t_room **room, int size)
{
	int		i;

	i = 0;
	printf("Bellman-Ford dist from start to other is:\n");
	while (i < size)
	{
		printf("room[%i] = %.f; ", i, room[i]->dist);
		i++;
	}
	printf("\n");
}

void			print_way(t_room **room, int end)
{
	t_room	*ptr;

	ptr = room[end];
	printf("Bellman-Ford path is: ");
	while (ptr->parent >= 0)
	{
		printf("%s ", ptr->name);
		ptr = room[ptr->parent];
	}
	printf("%s ", ptr->name);
	printf("\n\n");
}

void			print_path(t_input *input)
{
	t_path		**ways;
	t_room		**room;
	size_t		i;
	int			j;

	ways = input->path_arr->data;
	room = input->graph->data;
	i = 0;
	while (i < input->path_arr->next)
	{
		if (ways[i]->status == 1)
		{
			printf("%ld path is: ", i);
			j = 0;
			while (j < ways[i]->len)
			{
				if (j + 1 >= ways[i]->len || (j + 1 < ways[i]->len &&\
			ways[i]->way[j] != ways[i]->way[j + 1]))
					printf("%s ", room[ways[i]->way[j]]->name);
				j++;
			}
			printf("\n");
		}
		i++;
	}
}

void		print_edge(t_input *input)
{
	t_edge	*ptr;
	t_room	**room;

	ptr = input->edge_list;
	room = input->graph->data;
	while (ptr)
	{
		printf("Edge [%s][%i]-[%s][%i]\n", room[ptr->from]->name, ptr->from,\
		room[ptr->to]->name, ptr->to);
		printf("Weight: %i\n", ptr->weight);
		printf("Status: ");
		ptr->active ? printf("active\n") : printf("unactive\n");
		printf("\n");
		ptr = ptr->next;
	}
}
