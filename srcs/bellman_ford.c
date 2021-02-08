#include "lemin.h"

/*
 * если расстояние от старта до соседа больше, чем от старта до текущей + вес
 * ребра текущая-сосед (и это ребро активно), то обновить расстояние до соседа,
 * текущую сделать родителем соседа, соседа назначить ребенком текущей
 */

void			bellman_ford(t_input *input)
{
	t_edge		*ptr;
	t_room		**room;
	size_t		i;

	i = -1;
	room = input->graph->data;
	while (++i < input->graph->next)
	{
		ptr = input->edge_list;
		while (ptr)
		{
			if (ptr->active && room[ptr->to]->dist >\
			room[ptr->from]->dist + ptr->weight)
			{
				room[ptr->to]->dist = room[ptr->from]->dist + ptr->weight;
				room[ptr->to]->parent = ptr->from;
				room[ptr->from]->child = ptr->to;
			}
			ptr = ptr->next;
		}
	}
}
