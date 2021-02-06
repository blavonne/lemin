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

void			print_matrix_i(int **matrix, int size)
{
	int		h;
	int		w;

	h = 0;
	if (!matrix)
		return ;
	while (h < size)
	{
		w = 0;
		while (w < size)
		{
			printf("%2i ", matrix[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	printf("\n");
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
	printf("Bellman-Ford way is: ");
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
		printf("%ld way is: ", i);
		j = 0;
		while (j < ways[i]->len)
		{
			printf("%s ", room[ways[i]->step[j]]->name);
			j++;
		}
		printf("\n");
		i++;
	}
}
