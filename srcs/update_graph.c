#include "lemin.h"

static t_room		*clone_room(t_room *orig)
{
	t_room		*clone;

	clone = NULL;
	clone = create_room();
	clone->name = ft_strdup(orig->name);
	clone->out = 1;
	clone->parent = -1;
	clone->child = orig->id;
	clone->near = NULL;
	clone->dist = INF;
	return (clone);
}

void			dup_rooms(t_input *input)
{
	t_path	**path;
	t_room	**room;
	t_room	*dup;
	int		*way;
	int		i;

	i = 0;
	dup = NULL;
	path = input->path_arr->data;
	way = path[input->path_arr->next - 1]->way;
	room = input->graph->data;
	while (i < path[input->path_arr->next - 1]->len - 1)
	{
		dup = clone_room(room[way[i]]);
		dup->id = input->graph->next;
		if (!(push_in_vector(&input->graph, dup, sizeof(t_room *), POINTER)))
			error(MEMORY);
		i++;
	}
}

//void			include_dups(t_input *input)
//{
//	t_path		**path;
//	t_path		*ptr;
//	int			i;
//
//	path = input->path_arr->data;
//	ptr = path[input->path_arr->next - 1];
//	i = 0;
//	//дописать
//}

void			update_graph(t_input *input)
{
	if (input->path_arr->next)
	{
		dup_rooms(input);
		reverse_edges(input);
//		include_dups(input);
	}
}
