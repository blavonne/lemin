#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h> // не помню, разрешено ли
# include <sys/io.h> // не помню, разрешено ли
# include <math.h> //denied
# include <stdio.h> //denied

# define ARGS		0b1000000000000000
# define FILE		0b0100000000000000
# define ZERO		0b0010000000000000
# define NEG		0b0001000000000000
# define EMPTY		0b0000100000000000
# define MEMORY		0b0000010000000000
# define NOWAY		0b0000001000000000
# define S_ROOM		0b0000000100000000
# define E_ROOM		0b0000000010000000
# define DUPS		0b0000000001000000
# define INT		0b0000000000100000
# define HYPHEN		0b0000000000010000
# define VECTOR		100

# define COUNT		0b0000000000000000
# define ANY		0b0000000000001011
# define START		0b0000000000000001
# define ROOM		0b0000000000000010
# define LINK		0b0000000000000100
# define END		0b0000000000001000

# define INF		1.0 / 0.0

typedef struct s_input t_input;
typedef struct s_room t_room;
typedef struct s_vector t_vector;
typedef struct s_link t_link;
typedef struct s_path t_path;

struct			s_vector
{
	void	*data;
	size_t	size;
	size_t	next;
};

struct			s_link
{
	t_room	*room;
	int		status;
	t_link	*next;
};

/*
 * near is int vector and contains indexes of nearby vertexes
 */

struct			s_room
{
	char		*name;
	int			order; //индекс в векторе
	int			parent;
	t_vector	*near; //индексы соседей
	int			is_start;
	int			is_end;
	int			visited;
	int			ant_id;
	double		distance;
	int			coords[2];
};

struct			s_input
{
	t_vector	*rooms;
	int			**weight;
	int			**link;
	double		**dist;
	int			ants;
	int			expected;
	int			start_id;
	int			end_id;
};

struct			s_path
{
	int		*path;
	int		len;
};

void			read_input(int argc, char **argv, t_input *input);
void			read_ants_count(char *line, t_input *input);
void			read_room(char *line, t_input *input);
void			read_link(char *line, t_input *input);
void			check_input(t_input *input);

void			error(int reason);
int				push_in_vector(t_vector **v, void *data, size_t size, int type);
void			clean_vector(t_vector **v);
t_room			*create_room(void);

void			reset_visited(t_input *input);
void			reset_parent(t_input *input);
void			reset_dist(t_input *input);

int				**create_matrix_i(int size);
double			**create_matrix_d(size_t size);
void			feel_matrix(t_input *input, int **matrix);
void			print_matrix_i(int **matrix, int size);

void			dijkstra(t_input *input);
void			bellman_ford(t_input *input);

void			set_links(t_input *input);
void			set_dist(t_input *input); //Беллман-Форд
void			set_path(t_input *input);

#endif
