cmake_minimum_required(VERSION 3.25)
project(tic_tac_toe)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac_toe source/main.cpp source/board.cpp source/board.h source/gameEngine.cpp source/gameEngine.h)
target_link_libraries(tic_tac_toe ${SDL2_LIBRARIES})