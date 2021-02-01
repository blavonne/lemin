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
	int			name1;
	int			name2;

	i = 0;
	if (!(split = ft_strsplit(line, '-')))
		error(MEMORY);
	while(split[i++]);
	if (i != 3)
		error(HYPHEN);
	room = input->room->data;
	name1 = -1;
	name2 = -1;
	i = 0;
	while (i < input->room->next)
	{
		if (ft_strequ(split[0], room[i]->name))
			name1 = i;
		if (ft_strequ(split[1], room[i]->name))
			name2 = i;
		i++;
	}
	clean_two_dim((void ***)&split);
	if (name1 < 0 || name2 < 0)
		error(LINK);
	if (!push_in_vector(&room[name1]->near, &name2, sizeof(int), INT) || \
	!push_in_vector(&room[name2]->near, &name1, sizeof(int), INT))
		error(MEMORY);
}