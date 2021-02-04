#include "lemin.h"

t_path			*create_path(void)
{
	t_path		*obj;

	if (!(obj = (t_path *)malloc(sizeof(t_path))))
		error(MEMORY);
	ft_bzero(obj, sizeof(t_path));
	return (obj);
}
