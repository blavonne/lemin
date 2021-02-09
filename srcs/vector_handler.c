#include "lemin.h"

static t_vector	*create_vector(void)
{
	void		*data;
	t_vector	*vector;

	if (!(vector = (t_vector *)malloc(sizeof(t_vector))))
		error(MEMORY);
	if (!(data = malloc((VECTOR + 1) * 8)))
		error(MEMORY);
	vector->data = data;
	vector->size = (VECTOR + 1) * 8;
	vector->next = 0;
	return (vector);
}

static int		ptr_resize(t_vector **v)
{
	void			*tmp;

	if (!(tmp = malloc((*v)->size + (VECTOR + 1) * 8)))
		return (0);
	ft_memset(tmp, 0, (*v)->size + (VECTOR + 1) * 8);
	tmp = ft_memcpy(tmp, (*v)->data, (*v)->size);
	(*v)->size += (VECTOR + 1) * 8;
	free((*v)->data);
	(*v)->data = tmp;
	return (1);
}

static int		vector_resize(t_vector **v)
{
	void			*tmp;

	if (!(tmp = malloc((*v)->size + (VECTOR + 1) * 8)))
		return (0);
	ft_memset(tmp, 0, (*v)->size + (VECTOR + 1) * 8);
	tmp = ft_memcpy(tmp, (*v)->data, (*v)->size);
	(*v)->size += (VECTOR + 1) * 8;
	free((*v)->data);
	(*v)->data = tmp;
	return (1);
}

static int		push_pointer(t_vector **v, void *data, size_t size)
{
	char	**dst;
	char	*next;

	if (!(*v))
		(*v) = create_vector();
	if (size * (*v)->next + size > (*v)->size)
		if (!ptr_resize(v))
			return (0);
	dst = (*v)->data;
	next = data;
	dst[(*v)->next] = next;
	(*v)->next++;
	return (1);
}

static int		push_int(t_vector **v, void *data, size_t size)
{
	int		*arr;

	if (!(*v))
		(*v) = create_vector();
	if (size * (*v)->next + size > (*v)->size)
		if (!vector_resize(v))
			return (0);
	arr = (*v)->data;
	arr[(*v)->next] = *(int *)data;
	(*v)->next++;
	return (1);
}

int				push_in_vector(t_vector **v, void *data, size_t size, int type)
{
	if (type == PTR)
		return (push_pointer(v, data, size));
	else if (type == INT)
		return (push_int(v, data, size));
	return (0);
}
