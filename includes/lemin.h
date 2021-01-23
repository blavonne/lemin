#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/io.h>

# define ARGS		0b1000000000000000
# define FILE		0b0100000000000000
# define ZERO		0b0010000000000000
# define NEG		0b0001000000000000
# define EMPTY		0b0000100000000000
# define MEMORY		0b0000010000000000
# define NOWAY		0b0000001000000000

# define S_ROOM		0b0000000100000000
# define E_ROOM		0b0000000010000000
# define VECTOR		511

# define COUNT		0b0000000000000000
# define ANY		0b0000000000001011
# define START		0b0000000000000001
# define ROOM		0b0000000000000010
# define LINK		0b0000000000000100
# define END		0b0000000000001000

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
	int			visited;
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
void			read_room(char *line, t_input *input);
t_room			*create_room(void);
void			read_link(char *line, t_vector *rooms);
int				push_in_vector(t_vector **v, void *data, size_t size, int type);
void			clean_vector(t_vector **v);
void			check_input(t_input *input);

#endif
