#include "lemin.h"

double			**create_matrix_d(size_t size)
{
	double		**matrix;
	size_t		i;

	i = 0;
	if (!(matrix = (double **)malloc(sizeof(double *) * size)))
		error(MEMORY);
	while (i < size)
	{
		if (!(matrix[i] = (double *)malloc(sizeof(double) * size)))
			error(MEMORY);
		ft_bzero(matrix[i], sizeof(double) * size);
		i++;
	}
	return (matrix);
}

void			set_inf(double **matrix, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INF;
			j++;
		}
		i++;
	}
}

void			dist_init(t_input *input)
{
	int		*near;
	t_room	**room;
	double	**dist;
	size_t		i;
	size_t		j;

	room = input->rooms->data;
	i = 0;
	set_inf(input->dist_matrix, input->rooms->next);
	dist = input->dist_matrix;
	while (i < input->rooms->next)
	{
		if (room[i]->near)
		{
			near = room[i]->near->data;
			j = 0;
			while (j < room[i]->near->next)
			{
//			if (input->link_matrix[room[i]->order][near[j]])
//				dist[room[i]->order][near[j]] = 1;
				dist[room[i]->order][near[j]] = 1;
				j++;
			}
		}
		i++;
	}
}

void			print_distance(double **dist, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	printf("Dist matrix:\n");
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%3.f ", dist[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void			set_dist(t_input *input)
{
	size_t		zadannaja;
	size_t		tekuschaja;
	size_t		sosed;

	input->dist_matrix = create_matrix_d(input->rooms->next);
	dist_init(input);
	print_distance(input->dist_matrix, input->rooms->next);
	zadannaja = 0;
	int		a;

	a = 2;
	while (a--)
	{
		zadannaja = 0;
		while (zadannaja < input->rooms->next)
		{
			tekuschaja = 0;
			while (tekuschaja < input->rooms->next)
			{
				sosed = 0;
				while (sosed < input->rooms->next)
				{
					if (input->link_matrix[tekuschaja][sosed] == 1 &&\
				input->dist_matrix[zadannaja][sosed] >\
				(input->dist_matrix[zadannaja][tekuschaja] +\
				input->weight[tekuschaja][sosed]))
						input->dist_matrix[zadannaja][sosed] =\
					input->dist_matrix[zadannaja][tekuschaja] +\
					input->weight[tekuschaja][sosed];
					sosed++;
				}
				tekuschaja++;
			}
			zadannaja++;
		}
	}
	print_distance(input->dist_matrix, input->rooms->next);
}