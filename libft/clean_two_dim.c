#include "libft.h"

void		clean_two_dim(void ***arr)
{
	unsigned char	**ptr;
	int				i;

	i = 0;
	ptr = (unsigned char **)*arr;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	*arr = NULL;
}
