#include "lemin.h"

int				**create_matrix(int size)
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

void			feel_matrix(t_input *input, int **matrix)
{
	t_room	**room;
	int		*near;
	int		i;
	int		j;

	room = input->rooms->data;
	i = 0;
	while (i < input->rooms->next)
	{
		near = room[i]->near->data;
		j = 0;
		while (j < room[i]->near->next)
		{
			matrix[room[i]->order][near[j]] = 1;
			j++;
		}
		i++;
	}
}

void			print_matrix(int **matrix, int size)
{
	int		h;
	int		w;

	h = 0;
	while (h < size)
	{
		w = 0;
		while (w < size)
		{
			printf("%i ", matrix[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	printf("\n");
}