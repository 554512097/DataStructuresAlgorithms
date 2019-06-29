cmake_minimum_required(VERSION 3.13)

project(DataStructuresAlgorithms C)

set(CMAKE_C_STANDARD 99)

include_directories(linear_table)
include_directories(example)

aux_source_directory(linear_table LINEAR_TABLE_SRC)
aux_source_directory(example EXAMPLE_SRC)

add_executable(DataStructuresAlgorithms main.c ${LINEAR_TABLE_SRC} ${EXAMPLE_SRC} example/exam_seq_list.c example/exam_link_list.c example/exam_seq_stack.c example/exam_link_stack.c example/exam_seq_queue.c example/exam_link_queue.c)