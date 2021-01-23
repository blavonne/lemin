cmake_minimum_required(VERSION 3.17)
project(lemin C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
include_directories(includes)
add_subdirectory(libft)
add_executable(lemin main.c read_input.c includes/lemin.h error_handler.c read_ants_count.c read_cmd.c read_room.c room_handler.c read_link.c vector_handler.c cleaner.c)
target_link_libraries(lemin libft)