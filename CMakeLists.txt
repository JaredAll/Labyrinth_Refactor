cmake_minimum_required(VERSION 3.10)

project(Labyrinth)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB SOURCES
        ${PROJECT_SOURCE_DIR}/src/main/*.cpp
        ${PROJECT_SOURCE_DIR}/src/main/character/*.cpp
        ${PROJECT_SOURCE_DIR}/src/main/input/*.cpp)

add_executable(Labyrinth ${PROJECT_SOURCE_DIR}/src/main/Labyrinth.cpp ${SOURCES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_directories(
        Labyrinth PUBLIC
        "${PROJECT_SOURCE_DIR}/src/inc"
        "${PROJECT_SOURCE_DIR}/src/main"
)

target_link_libraries(Labyrinth PUBLIC ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})

target_include_directories(Labyrinth PUBLIC
        "${PROJECT_SOURCE_DIR}/src/inc"
        "${PROJECT_SOURCE_DIR}/src/main"
        )