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
# define POINTER	2
# define HYPHEN		0b0000000000010000
# define VECTOR		100
# define NONE		-1

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

struct			s_vector
{
	void	*data; // данные любого типа
	size_t	size; // выделенная память
	size_t	next; // индекс следующего для записи элемента (количество записанных элементов)
};

struct			s_path
{
	int			*step; // индексы вершин пути от S до E (t_room *graph->data[step[i]])
	int			len; // длина пути
	int			id; // индекс самого пути
	t_path		*next; // следующий путь, мб не нужно
};

struct			s_ant
{
	t_path		*way; // указатель на используемый путь, можно заменить на int id пути (t_path.id)
	int			id; // id муравья для вывода, дефолтное значение должно быть -1
	int			cur_step; // индекс текущего выполняемого шага в s_path (step[cur_step])
};

struct			s_room
{
	char		*name; //имя комнаты
	int			out; // out или in
	int			id; // порядковый номер (индекс) в векторе graph
	int			parent; // индекс вершины-родителя, заполняется после алгоритма Беллмана-Форда
	int			child; // индекс вершины-ребенка
	t_vector	*near; // индексы соседей (никогда не изменяются, все изменения в матрице смежностей)
	// используется для быстрого обращения к вершинам, к которым есть путь из данной, причем о его наличии надо
	// спрашивать в input->link[room->order][room[room->near->data[i]]->order]
	int			is_start; // является ли началом
	int			is_end; // является ли концом
	int			visited; // флаг посещенности, используется при проверке на дубликаты и в алгоритме Дийкстры
	t_ant		ant; // муравей в комнате, не ссылка, потому что - а зачем?
	double		distance; // расстояние от стартовой комнаты до этой
	int			coords[2]; // координаты комнаты
};

struct			s_input
{
	t_vector	*graph; //содержит все вершины графа
	int			**weight; //матрица веса
	int			**link; // матрица смежностей
	double		**dist; // матрица расстояний/достижимости
	int			ants; //количество муравьев
	int			expected; // валидация
	int			start_id; // индекс стартовой комнаты в graph (t_room *graph->data[start_id])
	int			end_id; // индекс финальной комнаты в graph (t_room *graph->data[end_id])
	t_vector	*path_arr; // вектор структур s_path
};

void			init_input(t_input *input);
void			read_input(int argc, char **argv, t_input *input);
void			read_ants_count(char *line, t_input *input);
void			read_room(char *line, t_input *input);
void			read_link(char *line, t_input *input);
void			check_input(t_input *input);

void			error(int reason);
int				push_in_vector(t_vector **v, void *data, size_t size, int type);
void			clean_vector(t_vector **v);

void			reset_visited(t_input *input);
void			reset_parent(t_input *input);
void			reset_dist(t_input *input);
void			relink_and_reweight(t_input *input);

t_room			*create_room(void);
t_path			*create_path(void);
int				**create_matrix_i(int size);
double			**create_matrix_d(size_t size);
void			feel_matrix_default_i(t_input *input, int **matrix);
void			print_matrix_i(int **matrix, int size);
void			print_path(t_input *input);

void			dijkstra(t_input *input);
void			bellman_ford(t_input *input);
void			suurbale(t_input *input);

void			set_command(char *line, t_input *input);
void			set_links(t_input *input);
void			set_dist(t_input *input); //Беллман-Форд для всех комнат
void			set_path(t_input *input);
void			set_matrix_default_i(t_input *input, int ***matrix);

int				is_comment(char *line);
int				is_command(char *line);
int				is_room(char *line);
int				is_link(char *line);

#endif
