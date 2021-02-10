#include "lemin.h"

/*
 * Формула количества строк - l + L - 1, где l - это длина пути,
 * L - количество муравьёв
 */

static int		check_way_to_end(t_input *input)
{
	t_room		**room;

	room = input->graph->data;
	if (room[input->end_id]->dist == INF)
		return (0);
	return (1);
}

/*
 * вернет 0, если в графе вообще нет пути к выходу
 * вернет 1, если максимальное количество путей найдено
 */

int				suurbale(t_input *input)
{
//	print_edge(input);
	reset_dist(input);
	reset_parent(input);
	bellman_ford(input);
	if (!check_way_to_end(input))
	{
		if (input->path_arr == NULL)
			return (0);
		return (1);
	}
	add_path(input);
	update_graph(input);
	printf("===========suurbale=============\n");
	print_path(input);
	printf("\n");
	if (split_paths(input))
	{
		printf("======suurbale after glue=======\n");
		print_path(input);
		printf("\n");
		suurbale(input);
	}
	else
		return (1);
}

/*
 * пройти по суурбале 1 раз, вернуть -1, если нет пути к выходу
 * после франкенштейна запустить суурбале ещё раз и после беллмана-форда
 * проверить потенциал
 * если вызывать франкештейна после каждого нового пути, можно сократить
 * количество операций в нем, сравнивая только последний путь с остальными
 */