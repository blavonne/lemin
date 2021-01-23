#include "lemin.h"

static void		check_link(int left, int right, t_room **room, char *line)
{
	int		l_len;
	int		r_len;

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

void			read_link(char *line, t_vector *rooms)
{
	int		left;
	int		right;
	int		i;
	t_room	**ptr;

	ptr = (t_room **)rooms->data;
	i = 0;
	left = -1;
	right = -1;
	while (i < rooms->next)
	{
		if (left < 0 && ft_strstr(line, ptr[i]->name))
			left = i;
		else if (left != -1 && ft_strstr(line, ptr[i]->name))
			right = i;
		i++;
	}
	if (left < 0 || right < 0)
		error(LINK);
	if (ft_strstr(line, ptr[left]->name) > ft_strstr(line, ptr[right]->name))
		ft_swap(&left, &right);
	check_link(left, right, ptr, line);
	if (!push_in_vector(&ptr[left]->ways, ptr[right], sizeof(char *), ROOM) ||\
	!push_in_vector(&ptr[right]->ways, ptr[left], sizeof(char *), ROOM))
		error(MEMORY);
}
