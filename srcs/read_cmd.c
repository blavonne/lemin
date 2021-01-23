#include "lemin.h"

void			read_cmd(char *line, t_input *input)
{
	if (!ft_strequ(line, "##start"))
		error(START);
	input->expected = S_ROOM;
}
