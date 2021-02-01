#include "lemin.h"

void		clean_vector(t_vector **v)
{
	t_room	**room;
	int		i;

	i = 0;
	room = (*v)->data;
	while (i < (*v)->next)
	{
		free(room[i]->name);
		room[i]->name = NULL;
		room[i]->near ? free(room[i]->near->data) : 0;
		free(room[i]->near);
		free(room[i]);
		room[i] = NULL;
		i++;
	}
	free((*v)->data);
	free(*v);
	(*v) = NULL;
}

void		reset_visited(t_input *input)
{
	t_room		**room;
	int			i;

	i = 0;
	room = input->rooms->data;
	while (i < input->rooms->next)
	{
		room[i]->visited = 0;
		i++;
	}
}

//добавить очистку интовой матрицы
