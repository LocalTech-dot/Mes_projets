cmake_minimum_required(VERSION 3.14)
project(sokoban C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra)

# --- GESTION DE LA PORTABILITÉ RAYLIB ---
set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "" FORCE)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)
FetchContent_MakeAvailable(raylib)

# --- CONSTRUCTION ---

add_executable(sokoban
        main.c
        sokoban_moteur.c
        sokoban.h
)

target_link_libraries(sokoban PRIVATE raylib)

# --- COPIE DES RESSOURCES ---
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ressources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/levels DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
