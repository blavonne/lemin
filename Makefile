NAME = lem-in
#BASE---------------------------------------------------------------------------
SRC_DIR = ./srcs/
INC_DIR = ./includes/
#LIBFT--------------------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_LIB = -L $(L_ROOT) -lft
#FLAGS--------------------------------------------------------------------------
FLAGS = -Wall -Werror -Wextra
#SOURCES------------------------------------------------------------------------
SRC = main.c\
	read_input.c\
	error_handler.c\
	read_ants_count.c\
	read_room.c\
	room_handler.c\
	read_link.c\
	vector_handler.c\
	cleaner.c\
	check_input.c\
	dijkstra.c\
	bellman_ford.c\
	link_matrix.c\
	distance_matrix.c\
	set_path.c
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