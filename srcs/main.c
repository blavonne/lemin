#include <stdio.h>
#include "lemin.h"

void		print_vector(t_vector *vector)
{
	int		i;
	t_room	**room;
	t_room	**related;
	int		j;

	i = 0;
	room = vector->data;
	while (i < vector->next)
	{
		j = 0;
		printf("Name №%i: %s (%i, %i)\n", room[i]->order, room[i]->name,\
		room[i]->coords[0], room[i]->coords[1]);
		if (room[i]->ways)
		{
			printf("Related with: ");
			related = room[i]->ways->data;
			while (j < room[i]->ways->next)
			{
				printf("%s ", related[j]->name);
				j++;
			}
			printf("\n");
		}
		if (room[i]->near)
		{
			printf("Related with: ");
			int		m;
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
	print_vector(input.rooms);
}

int			main(int argc, char **argv)
{
	t_input	input;

	ft_bzero(&input, sizeof(input));
	read_input(argc, argv, &input);
	check_input(&input);
	print_input(input);
	clean_visit(&input);
	dijkstra(&input);
	clean_vector(&input.rooms);
	return 0;
}
