#include "lemin.h"

void			input_init(t_input *input)
{
	ft_bzero(input, sizeof(t_input));
	input->end_id = -1;
	input->start_id = -1;
}
