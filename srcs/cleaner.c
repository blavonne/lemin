#include "lemin.h"

static void	clean_path(t_vector **v)
{
	t_path	**path;
	size_t	i;

	i = 0;
	if (*v)
	{
		path = (*v)->data;
		while (i < (*v)->next)
		{
			free(path[i]);
			path[i] = NULL;
			i++;
		}
		free((*v)->data);
		(*v)->data = NULL;
		free(*v);
		(*v) = NULL;
	}
}

static void	clean_room(t_vector **v)
{
	t_room	**room;
	size_t	i;

	i = 0;
	if (*v)
	{
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
		(*v)->data = NULL;
		free(*v);
		(*v) = NULL;
	}
}

static void	clean_int(t_vector **v)
{
	if (*v)
	{
		free((*v)->data);
		(*v)->data = NULL;
		free(*v);
		(*v) = NULL;
	}
}

void		clean_vector(t_vector **v, int type)
{
	if (type == ROOM)
		clean_room(v);
	else if (type == INT)
		clean_int(v);
	else if (type == PATH)
		clean_path(v);
}

void		clean_edge(t_edge **edge)
{
	t_edge	*list;
	t_edge	*next_list;

	list = *edge;
	while (list)
	{
		next_list = list->next;
		free(list);
		list = next_list;
	}
	*edge = NULL;
}
//добавить очистку интовой матрицы
//TODO: нормальная чистка!!!
