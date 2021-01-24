#include "lemin.h"

void		read_ants_count(char *line, t_input *input)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[0] == '0')
				error(ZERO);
			if ((line[i] < '0' || line[i] > '9') && !(i == 0 && line[0] == '+'))
				error(NEG);
			i++;
		}
		if (i)
		{
			input->ants = ft_atoi(line);
			input->expected = ANY;
		}
		else
			error(EMPTY);
	}
	else
		error(EMPTY);
}
