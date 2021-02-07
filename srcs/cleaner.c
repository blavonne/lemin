#include "lemin.h"

void		clean_vector(t_vector **v)
{
	t_room	**room;
	size_t	i;

	i = 0;
	room = (*v)->data;
	while (i < (*v)->next)
	{
		ft_strdel(&room[i]->name);
		if (room[i]->near)
		{
			free(room[i]->near->data);
			room[i]->near->data = NULL;
			free(room[i]->near);
			room[i]->near = NULL;
		}
		free(room[i]);
		room[i] = NULL;
		i++;
	}
	free((*v)->data);
	free(*v);
	(*v) = NULL;
}

//добавить очистку интовой матрицы
