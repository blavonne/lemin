#include <stdio.h>
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
				printf("graph[%i] ", ptr[m]);
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

int			main(int argc, char **argv)
{
	t_input	input;

	ft_bzero(&input, sizeof(input));
	input.end_id = -1;
	input.start_id = -1;
	read_input(argc, argv, &input);
	check_input(&input);
	print_input(input);
	set_links(&input);
//	dijkstra(&input);
//	bellman_ford(&input);
	suurbale(&input);
//	set_dist(&input);
//	set_path(&input);
	clean_vector(&input.graph);
	return 0;
}
