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
		input->dist = create_matrix_d(input->rooms->next);
	set_inf(input->dist, input->rooms->next);
	dist = input->dist;
	while (i < input->rooms->next)
	{
		j = 0;
		while (j < input->rooms->next)
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
	int			v;
	int			u;
	int			any;

	while (1)
	{
		any = 0;
		v = -1;
		while (++v < input->rooms->next)
		{
			u = -1;
			while (++u < input->rooms->next)
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
	int			i;

	dist_init(input);
	reset_parent(input);
	print_distance(input->dist, input->rooms->next);
	i = -1;
	while (++i < input->rooms->next)
		calc_dist(input->dist[i], input);
	print_distance(input->dist, input->rooms->next);
}

void			dist_check(t_input *input)
{
	int		i;
	int		j;

	i = 0;
	while (i < input->rooms->next)
	{
		j = 0;
		while (j < input->rooms->next)
		{
			if (input->dist[i][j] != input->dist[j][i])
				printf("[%i][%i] error!\n", i, j);
			j++;
		}
		i++;
	}
}