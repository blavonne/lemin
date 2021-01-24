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
		room[i]->ways ? free(room[i]->ways->data) : 0;
		free(room[i]->ways);
		room[i]->ways = NULL;
		free(room[i]);
		room[i] = NULL;
		i++;
	}
	free((*v)->data);
	free(*v);
	(*v) = NULL;
}