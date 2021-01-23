#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/io.h>

# define ARGS		1
# define FILE		2
# define ZERO		3
# define NEG		4
# define EMPTY		5
# define MEMORY		6
# define START		11
# define ROOM		12
# define END		13
# define LINK		14
# define S_ROOM		15
# define E_ROOM		16
# define VECTOR		511

typedef struct s_input t_input;
typedef struct s_room t_room;
typedef struct s_vector t_vector;

struct			s_vector
{
	void	*data;
	size_t	size;
	size_t	next;
};

struct			s_room
{
	char		*name;
	int			coords[2];
	t_vector	*ways;
	int			is_start;
	int			is_end;
};

struct			s_input
{
	int			ants;
	int			expected;
	t_vector	*rooms;
};

void			read_input(int argc, char **argv, t_input *input);
void			error(int reason);
void			read_ants_count(char *line, t_input *input);
void			read_cmd(char *line, t_input *input);
void			read_room(char *line, t_input *input);
t_room			*create_room(void);
void			read_link(char *line, t_vector *rooms);
int				push_in_vector(t_vector **v, void *data, size_t size, int type);
void			clean_vector(t_vector **v);

#endif
