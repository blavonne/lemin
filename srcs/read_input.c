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
	fd ? close(fd) : 0;
}
