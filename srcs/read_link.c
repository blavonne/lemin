#include "lemin.h"

static void		check_link(int left, int right, t_room **room, char *line)
{
	size_t		l_len;
	size_t		r_len;

	l_len = ft_strlen(room[left]->name);
	r_len = ft_strlen(room[right]->name);
	if (line[l_len] == '-' && ft_strlen(line) == l_len + r_len + 1)
		return ;
	else
		error(LINK);
}

/*
** this func checks that name of link exists
*/

void			read_link_old(char *line, t_vector *rooms)
{
	int		left;
	int		right;
	size_t	i;
	t_room	**room;

	room = (t_room **)rooms->data;
	i = 0;
	left = -1;
	right = -1;
	while (i < rooms->next)
	{
		if (left < 0 && ft_strstr(line, room[i]->name))
			left = i;
		else if (left != -1 && ft_strstr(line, room[i]->name))
			right = i;
		i++;
	}
	if (left < 0 || right < 0)
		error(LINK);
	if (ft_strstr(line, room[left]->name) < ft_strstr(line, room[right]->name))
		ft_swap(&left, &right);
	check_link(left, right, room, line);
	if (!push_in_vector(&room[left]->near, &right, sizeof(int), INT) || \
	!push_in_vector(&room[right]->near, &left, sizeof(int), INT))
		error(MEMORY);
}

//искать не вхождения!!! сплитить сразу!!!

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
