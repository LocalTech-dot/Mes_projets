cmake_minimum_required(VERSION 3.10)
project(sokoban C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)

# --- GESTION DE LA PORTABILITÉ RAYLIB ---
if(WIN32)

    set(RAYLIB_INCLUDE_DIR "C:/raylib/include")
    set(RAYLIB_LIBRARY "C:/raylib/lib/libraylib.a")

    set(SYSTEM_LIBS opengl32 gdi32 winmm)
else()
    # Configuration pour Linux (Standard)
    find_package(raylib REQUIRED)

    set(RAYLIB_INCLUDE_DIR ${RAYLIB_INCLUDE_DIRS})
    set(RAYLIB_LIBRARY raylib)

    set(SYSTEM_LIBS m pthread dl rt)
endif()

# --- CONSTRUCTION ---

add_executable(sokoban
        main.c
        sokoban_moteur.c
        sokoban.h
)

target_include_directories(sokoban PRIVATE ${RAYLIB_INCLUDE_DIR})

target_link_libraries(sokoban PRIVATE
        ${RAYLIB_LIBRARY}
        ${SYSTEM_LIBS}
)