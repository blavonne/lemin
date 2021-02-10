#ifndef LEMIN_H
# define LEMIN_H
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h> // не помню, разрешено ли
# include <math.h> //denied
# include <stdio.h> //denied

# define ARGS		0b1000000000000000
# define FILE		0b0100000000000000
# define ZERO		0b0010000000000000
# define NEG		0b0001000000000000
# define EMPTY		0b0000100000000000
# define MEMORY		0b0000010000000000
# define NOWAY		0b0000001000000000
# define START		0b0000000100000000
# define END		0b0000000010000000
# define DUPS		0b0000000001000000
# define INT		1
# define PTR		2
# define HYPHEN		0b0000000000010000
# define VECTOR		1
# define NONE		-42

# define UNKNOWN	0b0000000000000000
# define ES_DUPS	0b0000000000000001
# define ROOM		0b0000000000000010
# define LINK		0b0000000000000100

# define INF		1.0 / 0.0

typedef struct s_vector t_vector; // структура, описывающая тип данных вектор
// вектор - это всё равно что массив любых данных,
// хранящий свой размер и заполненность; аналог вектора из с++
typedef struct s_path t_path; // структура, описывающая путь от S до E
typedef struct s_ant t_ant; // структура, описывающая муравья
typedef struct s_input t_input; // структура, описывающая все входные данные
typedef struct s_room t_room; // структура, описывающая вершину
typedef struct s_edge t_edge;

struct			s_vector
{
	void		*data; // данные любого типа
	size_t		size; // выделенная память
	size_t		next; // индекс следующего для записи элемента (количество записанных элементов)
};

struct			s_path
{
	int			*way; // индексы вершин пути от S до E (t_room *graph->data[way[i]])
	int			len; // длина пути
	int			real_len; // длина пути без повторов
	int			id; // индекс самого пути
	int			status; // 0 off, 1 on
	int			priority; // приоритет пути (самые короткие имеют 0, остальные отрицательные)
	int			marked; // учтено при анализе приоритета 1|0
	int			replace;
	t_path		*next; // следующий путь, мб не нужно
};

struct			s_ant
{
	t_path		*path; // указатель на используемый путь, можно заменить на id пути (t_path.id)
	int			id; // id муравья для вывода, дефолтное значение должно быть -1
	int			cur_step; // индекс текущего выполняемого шага в s_path (way[cur_step])
};

struct			s_edge
{
	int			from;
	int			to;
	int			weight;
	int			active;
	t_edge		*next;
};

struct			s_room
{
	char		*name; //имя комнаты
	int			id; // порядковый номер (индекс) в векторе graph
	int			parent; // индекс вершины-родителя, заполняется после алгоритма Беллмана-Форда
	int			child; // индекс вершины-ребенка
	int			is_start; // является ли началом
	int			is_end; // является ли концом
	t_ant		*ant; // муравей в комнате, не ссылка, потому что - а зачем?
	double		dist; // расстояние от стартовой комнаты до этой
	int			coords[2]; // координаты комнаты
	int			is_copy; // является копией
	int			is_orig; // является оригиналом
	int			copy_id; // id копии в векторе
	int			orig_id; // id оригинала в векторе
	t_vector	*near; // индексы соседей (никогда не изменяются, все изменения в матрице смежностей)
	// используется для быстрого обращения к вершинам, к которым есть путь из данной, причем о его наличии надо
	// спрашивать в input->link[room->id][room[room->near->data[i]]->id]
};

struct			s_input
{
	t_vector	*graph; //содержит все вершины графа
	int			ants; //количество муравьев
	int			expected; // валидация
	int			start_id; // индекс стартовой комнаты в graph (t_room *graph->data[start_id])
	int			end_id; // индекс финальной комнаты в graph (t_room *graph->data[id])
	t_vector	*path_arr; // вектор структур s_path
	t_edge		*edge_list;
};

void			read_input(int argc, char **argv, t_input *input);
void			read_ants_count(char *line, t_input *input);
void			read_room(char *line, t_input *input);
void			read_link(char *line, t_input *input);
void			check_input(t_input *input);

void			error(int reason);
int				push_in_vector(t_vector **v, void *data, size_t size, int type);
void			clean_vector(t_vector **v, int type);

void			reset_parent(t_input *input);
void			reset_dist(t_input *input);
void			reset_marked(t_path **path, size_t len);
void			reverse_edges(t_input *input);

t_room			*create_room(void);
t_path			*create_path(void);
t_edge			*create_edge();

void			bellman_ford(t_input *input);
int				suurbale(t_input *input);
int				frankenstein(t_input *input);
void			update_graph(t_input *input);
int				split_paths(t_input *input);
int				check_len(t_input *input, size_t i, size_t j, int *inter);

void			set_command(char *line, t_input *input);
void			add_path(t_input *input);
void			add_edge(t_edge **head, int from, int to);
void			set_active(t_edge *head, int from, int to, int value);
void			set_weight(t_edge *head, int from, int to, int value);
void			set_priority(t_path **path, size_t len);
void			set_real_len(t_path **path, size_t len);

int				is_comment(char *line);
int				is_command(char *line);
int				is_room(char *line);
int				is_link(char *line);

void			print_path(t_input *input);
void			print_input(t_input input);
void			print_vector(t_vector *vector);
void			print_way(t_room **room, int end);
void			print_dist(t_room **room, int size);
void			print_edge(t_input *input);

int				count_paths(t_input *input);
void			print_output(t_input *input);
void			ant_management(t_input *input, t_room **rooms, t_path **paths, size_t active);

#endif
