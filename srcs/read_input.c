#include "lemin.h"

static int	check_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int	is_comment(char *line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if ((i == 0 && line[0] != '#') || (i == 1 && line[1] == '#' &&\
			line[0] == '#'))
				return (0);
			else if (i == 1 && line[1] != '#' && line[0] == '#')
				return (1);
			i++;
		}
	}
	else
		error(EMPTY);
	return (0);
}

static int	is_command(char *line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (i == 1 && line[1] == '#' && line[0] == '#')
				if (!(ft_strequ("##start", line)) &&\
				!(ft_strequ("##end", line)))
					return (1);
			i++;
		}
	}
	else
		error(EMPTY);
	return (0);
}

static void	check_dups(t_input *input)
{
	size_t	i;
	size_t		j;
	t_room	**room;
	char	*name;
	int		*coords;

	i = 0;
	room = input->rooms->data;
	while (room && i < input->rooms->next)
	{
		coords = room[i]->coords;
		name = room[i]->name;
		j = i;
		while (++j < input->rooms->next)
		{
			if (ft_strequ(name, room[j]->name) || (coords[0] ==\
			room[j]->coords[0] && coords[1] == room[j]->coords[1]))
				error(DUPS);
		}
		i++;
	}
}

//старт необязательно идёт первым, возможен любой порядок

void		read_input(int argc, char **argv, t_input *input)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc > 2 || (argc == 2 && !check_file(argv[1])))
		argc > 2 ? error(ARGS) : error(FILE);
	fd = (argc == 1) ? 0 : open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (is_comment(line) || is_command(line))
			ft_strdel(&line);
		else if (input->expected == COUNT)
			read_ants_count(line, input);
		else if(input->expected & LINK)
		{
			read_link(line, input);
			input->expected = input->expected & LINK;
		}
		else if (input->expected & ANY || input->expected == E_ROOM ||\
		input->expected == S_ROOM)
			read_room(line, input);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	check_dups(input);
	fd ? close(fd) : 0;
}
