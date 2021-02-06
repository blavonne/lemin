#include "lemin.h"

/*
 * если расстояние от старта до соседа больше, чем от старта до текущей + вес
 * ребра текущая-сосед (и это ребро активно), то обновить расстояние до соседа,
 * текущую сделать родителем соседа, соседа назначить ребенком текущей
 */

void			bellman_ford(t_input *input)
{
	t_room		**room;
	t_edge		*ptr;
	size_t		i;
	size_t		any;

	room = input->graph->data;
	while (1)
	{
		i = -1;
		any = 0;
		while (++i < input->graph->next)
		{
			ptr = room[i]->edge_list;
			while (ptr)
			{
				if (ptr->active)
				{
					if (room[ptr->id]->dist > room[i]->dist + ptr->weight)
					{
						room[ptr->id]->dist = room[i]->dist + ptr->weight;
						room[ptr->id]->parent = room[i]->id;
						room[i]->child = ptr->id;
						any = 1;
					}
				}
				ptr = ptr->next;
			}
		}
		if (!any)
			break ;
	}
}
