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
		related = room[i]->ways->data;
		printf("Name: %s (%i, %i)\n", room[i]->name, room[i]->coords[0],\
		room[i]->coords[1]);
		printf("Related with: ");
		while (j < room[i]->ways->next)
		{
			printf("%s ", related[j]->name);
			j++;
		}
		printf("\n\n");
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
	print_input(input);
	clean_vector(&input.rooms);
	return 0;
}
