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
	double	**dist;
	size_t		i;
	size_t		j;

	i = 0;
	if (!input->dist)
		input->dist = create_matrix_d(input->room->next);
	set_inf(input->dist, input->room->next);
	dist = input->dist;
	while (i < input->room->next)
	{
		j = 0;
		while (j < input->room->next)
		{
			if (input->link[i][j] == 1)
				dist[i][j] = 1;
			j++;
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

static void		calc_dist(double *dist, t_input *input)
{
	size_t		v;
	size_t		u;
	int			any;

	while (1)
	{
		any = 0;
		v = -1;
		while (++v < input->room->next)
		{
			u = -1;
			while (++u < input->room->next)
			{
				if (input->link[v][u] == 1 && dist[v] > dist[u] +\
				input->weight[v][u])
				{
					dist[v] = dist[u] + input->weight[v][u];
					any = 1;
				}
			}
		}
		if (!any)
			break ;
	}
}

void			set_dist(t_input *input)
{
	size_t			i;

	dist_init(input);
	print_distance(input->dist, input->room->next);
	i = -1;
	while (++i < input->room->next)
		calc_dist(input->dist[i], input);
	print_distance(input->dist, input->room->next);
}

void			dist_check(t_input *input)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < input->room->next)
	{
		j = 0;
		while (j < input->room->next)
		{
			if (input->dist[i][j] != input->dist[j][i])
				printf("[%ld][%ld] error!\n", i, j);
			j++;
		}
		i++;
	}
}
