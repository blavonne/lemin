#include "lemin.h"

static t_room	*copy_room(t_room *orig)
{
	t_room		*clone;

	clone = NULL;
	clone = create_room();
	if (!(clone->name = ft_strdup(orig->name)))
		error(MEMORY);
	clone->out = 1;
	clone->parent = -1;
	clone->child = orig->id;
	clone->dist = INF;
	return (clone);
}

//void			relink(int clone, t_input *input)
//{
//	t_room		**room;
//	int			orig;
//	t_edge		*orig_out;
//	t_edge		*neu;
//
//	room = input->graph->data;
//	orig = room[clone]->child;
//	orig_out = room[orig]->edge_list;
//	while (orig_out)
//	{
//
//	}
//}

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
		dup = copy_room(room[way[i]]);
		dup->id = input->graph->next;
		dup->edge_list = copy_edge_list(room[way[i]]->edge_list);
		if (!(push_in_vector(&input->graph, dup, sizeof(t_room *), POINTER)))
			error(MEMORY);
		add_edge(input, dup->id, way[i]); //добавили вершину copy->orig
		set_edge(room[dup->id], way[i], 0, 1); //сделали вес copy->orig = 0
//		relink(dup->id, input);
		i++;
	}
}

void			update_graph(t_input *input)
{
	if (input->path_arr->next)
	{
		dup_rooms(input);
		reverse_edges(input);
	}
}
