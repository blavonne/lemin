#include "lemin.h"

/*
** this func checks that name of link exists
*/

void			read_link(char *line, t_input *input)
{
	char		**split;
	t_room		**room;
	size_t		i;
	int			id1;
	int			id2;

	i = 0;
	if (input->start_id < 0 || input->end_id < 0)
		error(UNKNOWN);
	if (!(split = ft_strsplit(line, '-')))
		error(MEMORY);
	while(split[i++]);
	room = input->graph->data;
	id1 = -1;
	id2 = -1;
	i = 0;
	while (i < input->graph->next)
	{
		if (ft_strequ(split[0], room[i]->name))
			id1 = i;
		if (ft_strequ(split[1], room[i]->name))
			id2 = i;
		i++;
	}
	clean_two_dim((void ***)&split);
	if (id1 < 0 || id2 < 0)
		error(LINK);
	if (!push_in_vector(&room[id1]->near, &id2, sizeof(int), INT) || \
	!push_in_vector(&room[id2]->near, &id1, sizeof(int), INT))
		error(MEMORY);
	add_edge(&input->edge_list, id1, id2);
	add_edge(&input->edge_list, id2, id1);
}
