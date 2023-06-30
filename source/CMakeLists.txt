cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")

project(tic_tac_toe)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp board.h board.cpp gameEngine.h gameEngine.cpp)
target_link_libraries(tic_tac_toe ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
