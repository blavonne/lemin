#include "lemin.h"

static t_room	*copy_room(t_room *orig)
{
	t_room		*clone;

	clone = NULL;
	clone = create_room();
	if (!(clone->name = ft_strdup(orig->name)))
		error(MEMORY);
	clone->out = 1;
	clone->parent = NONE;
	clone->child = orig->id;
	clone->dist = INF;
	clone->is_orig = 0;
	clone->orig_id = orig->id;
	clone->is_copy = 1;
	clone->copy_id = NONE;
	return (clone);
}

void			replace_from(t_edge *head, int from, int except, int replace)
{
	t_edge		*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->from == from && ptr->to != except)
			ptr->from = replace;
		ptr = ptr->next;
	}
}

void			replace_to(t_edge *head, int from, int to, int replace)
{
	t_edge		*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->from == from && ptr->to == to)
			ptr->to = replace;
		ptr = ptr->next;
	}
}

void			dup_rooms(t_input *input)
{
	t_path	**path;
	t_room	**room;
	t_room	*dup;
	int		*way;
	int		i;

	path = input->path_arr->data;
	way = path[input->path_arr->next - 1]->way;
	room = input->graph->data;
	i = path[input->path_arr->next - 1]->len - 1;
	while (--i >= 0)
	{
		if (room[way[i]]->is_orig && room[way[i]]->copy_id == NONE)
		{
			dup = copy_room(room[way[i]]);
			dup->id = input->graph->next;
			room[way[i]]->copy_id = dup->id;
			if (!(push_in_vector(&input->graph, dup, sizeof(t_room *), PTR)))
				error(MEMORY);
			replace_from(input->edge_list, way[i], room[way[i]]->parent,\
			dup->id);
			add_edge(&input->edge_list, dup->id, way[i]);
			set_weight(input->edge_list, dup->id, way[i], 0);
			replace_to(input->edge_list, room[way[i]]->child, way[i], dup->id);
		}
	}
}

void			update_graph(t_input *input)
{
	if (input->path_arr->next)
	{
		reverse_edges(input);
		dup_rooms(input);
	}
}
