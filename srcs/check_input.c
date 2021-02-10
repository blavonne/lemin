#include "lemin.h"

int			check_dups(t_input *input)
{
	size_t	i;
	size_t	j;
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
				return (0);
		}
		i++;
	}
	return (1);
}

void		check_input(t_input *input)
{
	if (!(check_dups(input)))
		error(DUPS);
}
