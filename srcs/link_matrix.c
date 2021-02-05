#include "lemin.h"

int				**create_matrix_i(int size)
{
	int		**matrix;
	int		i;

	if (!(matrix = (int **)malloc(sizeof(int *) * size)))
		error(MEMORY);
	i = 0;
	while (i < size)
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * size)))
			error(MEMORY);
		ft_bzero(matrix[i], sizeof(int) * size);
		i++;
	}
	return (matrix);
}

void			feel_matrix_default_i(t_input *input, int **matrix)
{
	t_room	**room;
	int		*near;
	size_t	i;
	size_t	j;

	room = input->graph->data;
	i = 0;
	while (i < input->graph->next)
	{
		if (room[i]->near)
		{
			near = room[i]->near->data;
			j = 0;
			while (j < room[i]->near->next)
			{
				matrix[room[i]->id][near[j]] = 1;
				j++;
			}
		}
		i++;
	}
}

void			set_matrix_default_i(t_input *input, int ***matrix)
{
	if (!(*matrix))
	{
		*matrix = create_matrix_i(input->graph->next);
		feel_matrix_default_i(input, (*matrix));
	}
}

void			print_matrix_i(int **matrix, int size)
{
	int		h;
	int		w;

	h = 0;
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

void			set_links(t_input *input)
{
	input->link = create_matrix_i(input->graph->next);
	feel_matrix_default_i(input, input->link);
	printf("set_links matrix is:\n");
	print_matrix_i(input->link, input->graph->next);
}
