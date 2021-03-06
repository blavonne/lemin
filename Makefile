NAME = lem-in
#BASE---------------------------------------------------------------------------
SRC_DIR = ./srcs/
INC_DIR = ./includes/
#LIBFT--------------------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_LIB = -L $(L_ROOT) -lft
#FLAGS--------------------------------------------------------------------------
FLAGS = -Wall -Werror -Wextra -g
#SOURCES------------------------------------------------------------------------
SRC = ant_management.c\
	bellman_ford.c\
	check_input.c\
	check_len.c\
	cleaner.c\
	edge_handler.c\
	error_handler.c\
	frankenstein.c\
	is_something.c\
	main.c\
	path_handler.c\
	print_any.c\
	print_output.c\
	read_ants_count.c\
	read_input.c\
	read_link.c\
	read_room.c\
	reset.c\
	set_command.c\
	split_paths.c\
	suurbale.c\
	update_graph.c\
	vector_handler.c
OBJ = $(SRC:%.c=%.o)
#HEADERS------------------------------------------------------------------------
HEADERS = -I $(INC_DIR) -I $(L_ROOT)
#builder------------------------------------------------------------------------
all: $(NAME)
-include $(OBJ:.o=.d)
# build external libraries------------------------------------------------------
$(LIBFT): make_libft
make_libft:
	$(MAKE) -C $(L_ROOT)
# build filler------------------------------------------------------------------
$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(HEADERS) $(FLAGS) $(L_LIB)
%.o: $(SRC_DIR)%.c
	gcc -c $< -o $@ $(HEADERS) $(FLAGS) -MMD
# clean section-----------------------------------------------------------------
clean:
	$(MAKE) -C $(L_ROOT) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ:.o=.d)
fclean: clean
	$(MAKE) -C $(L_ROOT) fclean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re make_libft
