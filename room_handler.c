#include "lemin.h"

t_room			*create_room(void)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		error(MEMORY);
	ft_bzero(room, sizeof(t_room));
	return (room);
}
