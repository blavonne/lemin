#include "lemin.h"

void			turn_off_link(t_input *input)
{
	t_room		**room;
	t_room		*ptr;

	room = input->rooms->data;
	ptr = room[input->end_id];
	while (ptr->is_start != 1)
	{
		input->weight[ptr->order][ptr->parent] = -1;
		input->link[ptr->parent][ptr->order] = 0;
		ptr = room[ptr->parent];
	}
}

void			set_path(t_input *input)
{
//	t_vector	*path;
//	t_room		**room;
//	t_room		*ptr;
//
//	path = NULL;
//	room = input->rooms->data;
//	ptr = room[input->end_id];
//	if (!(push_in_vector(&path, &ptr->parent, sizeof(int), INT)))
//		error(MEMORY);
//	input->link[ptr->parent][ptr->order] = 0;
//	while (ptr->is_start != 1)
//	{
//		ptr = room[ptr->parent];
//		input->link[ptr->parent][ptr->order] = 0;
//		if (!(push_in_vector(&path, &ptr->parent, sizeof(int), INT)))
//			error(MEMORY);
//	}
	turn_off_link(input);
	print_matrix(input->link, input->rooms->next);
	print_matrix(input->weight, input->rooms->next);
}
