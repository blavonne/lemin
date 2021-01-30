#include "lemin.h"

void	error(int reason)
{
	if (reason & ARGS)
		ft_putstr_fd("Too many args.\n", 2);
	if (reason & FILE)
		ft_putstr_fd("No such file.\n", 2);
	if (reason & ZERO)
		ft_putstr_fd("Zero ants!\n", 2);
	if (reason & NEG)
		ft_putstr_fd("Negative count of ants or not integer value!\n", 2);
	if (reason & EMPTY)
		ft_putstr_fd("Unexpected empty or incomplete line.\n", 2);
	if (reason & START)
		ft_putstr_fd("Expected ##start or ##end, got something else.\n", 2);
	if (reason & ROOM)
		ft_putstr_fd("Error in room area.\n", 2);
	if (reason & MEMORY)
		ft_putstr_fd("Memory error (malloc).\n", 2);
	if (reason & LINK)
		ft_putstr_fd("Error in link area.\n", 2);
	if (reason & NOWAY)
		ft_putstr_fd("No way to end.\n", 2);
	if (reason & DUPS)
		ft_putstr_fd("Error: room duplicate or the same coords.\n", 2);
	if (reason & HYPHEN)
		ft_putstr_fd("Error: room name includes hyphen ('-').\n", 2);
	exit(1);
}
