#include "lemin.h"

t_path			*create_path(void)
{
	t_path		*obj;

	if (!(obj = (t_path *)malloc(sizeof(t_path))))
		error(MEMORY);
	ft_bzero(obj, sizeof(t_path));
	return (obj);
}

void			print_path(t_input *input)
{
	t_path		**ways;
	t_room		**room;
	size_t		i;
	size_t		j;

	ways = input->path_arr->data;
	room = input->graph->data;
	i = 0;
	while (i < input->path_arr->next)
	{
		printf("%ld way is: ", i);
		j = 0;
		while (j < ways[i]->len)
		{
			printf("%s ", room[ways[i]->step[j]]->name);
			j++;
		}
		printf("\n");
		i++;
	}
}
