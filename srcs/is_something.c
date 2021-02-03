#include "lemin.h"

int			is_comment(char *line)
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

int			is_command(char *line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (i == 1 && line[1] == '#' && line[0] == '#')
				return (1);
			i++;
		}
	}
	else
		error(EMPTY);
	return (0);
}

int			is_link(char *line)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

int			is_room(char *line)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}
