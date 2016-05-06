cmake_minimum_required(VERSION 3.2)
project(Graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES
        src/adjacency_matrix.cpp
        src/adjacency_matrix.h
        src/define.h
        src/incidence_list.cpp
        src/incidence_list.h
        src/list_of_edges.cpp
        src/list_of_edges.h
        src/main.cpp
        src/successors_list.cpp
        src/successors_list.h
        src/testing_cycles.cpp
        src/testing_cycles.h
        src/testing_sorting.cpp
        src/testing_sorting.h
        src/utils.cpp
        src/utils.h)

add_executable(Graphs ${SOURCE_FILES})