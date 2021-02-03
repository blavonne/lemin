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

static void	check_dups(t_input *input)
{
	size_t	i;
	size_t		j;
	t_room	**room;
	char	*name;
	int		*coords;

	i = 0;
	room = input->graph->data;
	while (i < input->graph->next)
	{
		coords = room[i]->coords;
		name = room[i]->name;
		j = i;
		while (++j < input->graph->next)
		{
			if (ft_strequ(name, room[j]->name) || (coords[0] ==\
			room[j]->coords[0] && coords[1] == room[j]->coords[1]))
				error(DUPS);
		}
		i++;
	}
}


static int	check_command(char *line, t_input *input)
{
	int		start;
	int		end;

	start = ft_strequ(line, "##start");
	end = ft_strequ(line, "##end");
	if (!start && !end)
		return (0);
	if (start && input->start_id != -1)
		return (-1);
	if (end && input->end_id != -1)
		return (-1);
	if (start && input->start_id == -1)
		return (2);
	if (end && input->end_id == -1)
		return (3);
	return (1);
}

void		set_command(char *line, t_input *input)
{
	int		check;

	check = check_command(line, input);
	if (check < 0)
		error(START | END | DUPS);
	else if (check == 2)
		input->expected = S_ROOM;
	else if (check == 3)
		input->expected = E_ROOM;
}

void		set_expected(t_input *input)
{
	int			expected;

	expected = 0;
	if (input->start_id < 0)
		expected |= START;
	if (input->end_id < 0)
		expected |= END;
	if (input->start_id >= 0 && input->end_id >= 0)
		expected |= LINK;
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
		if (is_comment(line))
			ft_strdel(&line);
		else if (is_command(line))
			set_command(line, input);
		else if (input->ants == 0)
			read_ants_count(line, input);
		else if (input->ants && is_link(line))
			read_link(line, input);
		else if (input->ants && is_room(line))
			read_room(line, input);
		else
			error(UNKNOWN);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	check_dups(input);
	fd ? close(fd) : 0;
}
