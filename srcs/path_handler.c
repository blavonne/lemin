#include "lemin.h"

t_path			*create_path(void)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		error(MEMORY);
	ft_bzero(path, sizeof(t_path));
	return (path);
}

void			add_path_back(t_path **head, t_path *last)
{
	t_path	*ptr;

	ptr = (*head);
	if (ptr && last)
	{
		while (ptr->next)
			ptr = ptr->next;
		last->index = ptr->index++;
		ptr->next = last;
	}
}

void			init_path(t_path **path, int len)
{
	t_path	*ptr;

	ptr = (*path);
	if (ptr && len > 0)
	{
		if (!(ptr->step = (int *)malloc(sizeof(int) * len)))
			error(MEMORY);
		ft_memset(ptr->step, -1, sizeof(int) * len);
		ptr->len = len;
	}
}

void			add_step_to_path(int **arr, int step)
{
	int		*ptr;
	int		i;

	ptr = (*arr);
	i = 0;
	if (ptr)
	{
		while (ptr[i] != -1)
			i++;
		ptr[i] = step;
	}
}
