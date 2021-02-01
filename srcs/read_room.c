#include "lemin.h"

static void		add_room(t_input *input, char *name, int x, int y)
{
	t_room	*room;

	room = create_room();
	if (!(room->name = ft_strdup(name)))
		error(MEMORY);
	room->coords[0] = x;
	room->coords[1] = y;
	if (!push_in_vector(&input->room, (void *)room, sizeof(t_room *), POINTER))
		error(MEMORY);
	room->order = input->room->next - 1;
	if (input->expected == S_ROOM)
	{
		room->is_start = 1;
		input->start_id = room->order;
		input->expected = END | ROOM;
	}
	if (input->expected == E_ROOM)
	{
		room->is_end = 1;
		input->end_id = room->order;
		input->expected = LINK | ROOM | START;
	}
}

void			check_is_number(char *line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (i == 0 && line[i] == 0)
				error(ROOM);
			if ((line[i] < '0' || line[i] > '9') && !(i == 0 && line[0] == '+'))
				error(ROOM);
			i++;
		}
	}
	else
		error(EMPTY);
}

static void		check_name(char *line)
{
	int		i;

	i = 0;
	if (line)
	{
		if (line[0] == 'L' || line[0] == '#' || line[0] == '\0')
			error(ROOM);
		while (line[i])
		{
			if (line[i] == '-')
				error(HYPHEN);
			i++;
		}
	}
	else
		error(EMPTY);
}

void			read_room(char *line, t_input *input)
{
	char		**split;
	int			i;
	int			coords[2];

	i = 0;
	if (!(split = ft_strsplit(line, ' ')))
		error(EMPTY);
	if (split[0] && (ft_strequ(split[0], "##end") || ft_strequ(split[0],\
	"##start")) && !split[1])
	{
		input->expected = (ft_strequ(split[0], "##end")) ? E_ROOM : S_ROOM;
		clean_two_dim((void ***)&split);
		return ;
	}
	else if ((ft_strequ(split[0], "##end") || ft_strequ(split[0], "##start"))\
	&& split[1])
		error(START);
	while (split[i])
	{
		(i == 0) ? check_name(split[0]) : 0;
		(i == 1 || i == 2) ? check_is_number(split[i]) : 0;
		i++;
	}
	if (i != 3)
		error(ROOM);
	coords[0] = ft_atoi(split[1]);
	coords[1] = ft_atoi(split[2]);
	add_room(input, split[0], coords[0], coords[1]);
	clean_two_dim((void ***)&split);
}
