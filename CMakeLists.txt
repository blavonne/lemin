cmake_minimum_required(VERSION 3.17)
project(lemin C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
include_directories(includes)
add_subdirectory(libft)
add_executable(lemin srcs/main.c srcs/read_input.c includes/lemin.h srcs/error_handler.c srcs/read_ants_count.c srcs/read_room.c srcs/read_link.c srcs/vector_handler.c srcs/cleaner.c srcs/check_input.c srcs/bellman_ford.c srcs/suurbale.c srcs/reset.c srcs/path_handler.c srcs/is_something.c srcs/set_command.c srcs/edge_handler.c srcs/print_any.c srcs/update_graph.c srcs/path_handler.c srcs/ant_management.c srcs/frankenstein.c srcs/print_output.c srcs/split_paths.c srcs/check_len.c srcs/check_path.c srcs/has_intersection.c)
target_link_libraries(lemin libft)