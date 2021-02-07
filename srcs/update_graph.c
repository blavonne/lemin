#include "lemin.h"

void			dup_rooms(t_input *input)
{
	t_path	**path;
	t_room	**room;
	t_room	*dup;
	int		*way;
	int		i;

	i = 0;
	path = input->path_arr->data;
	way = path[input->path_arr->next - 1]->way;
	room = input->graph->data;
	while (i < path[input->path_arr->next - 1]->len - 1)
	{
		dup = create_room();
		dup->name = ft_strdup(room[way[i]]->name);
		dup->out = 1;
		dup->id = input->graph->next;
		dup->parent = -1;
		dup->child = room[way[i]]->id;
		//dup->near = room[way[i]]->near;
		dup->dist = INF;
		room[room[way[i]]->parent]->child = dup->id;
		if (!(push_in_vector(&input->graph, (void *)dup, sizeof(t_room *), POINTER)))
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
		dup_rooms(input); //пока не работает
		reverse_edges(input);
//		include_dups(input);
	}
}
