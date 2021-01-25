cmake_minimum_required(VERSION 3.17)
project(lemin C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
include_directories(includes)
add_subdirectory(libft)
add_executable(lemin srcs/main.c srcs/read_input.c includes/lemin.h srcs/error_handler.c srcs/read_ants_count.c srcs/read_room.c srcs/room_handler.c srcs/read_link.c srcs/vector_handler.c srcs/cleaner.c srcs/check_input.c srcs/dijkstra.c srcs/bellman_ford.c srcs/set_deadlock_off.c srcs/matrix.c)
target_link_libraries(lemin libft)