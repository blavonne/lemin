#include "lemin.h"

void			set_deadlock_off(t_input *input)
{
	input->link_matrix = create_matrix(input->rooms->next);
	feel_matrix(input, input->link_matrix);
	print_matrix(input->link_matrix, input->rooms->next);
}