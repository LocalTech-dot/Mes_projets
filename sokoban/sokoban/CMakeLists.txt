cmake_minimum_required(VERSION 3.10)
project(sokoban C)

set(CMAKE_C_STANDARD 99)

find_path(RAYLIB_INCLUDE_DIR raylib.h)
find_library(RAYLIB_LIBRARY raylib)

add_executable(sokoban main.c sokoban_moteur.c sokoban.h)

target_include_directories(sokoban PRIVATE ${RAYLIB_INCLUDE_DIR})
target_link_libraries(sokoban raylib m pthread dl rt X11)

add_compile_options(-Wall -Wextra -Werror)