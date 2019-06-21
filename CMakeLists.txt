cmake_minimum_required(VERSION 3.13)

project(DataStructuresAlgorithms C)

set(CMAKE_C_STANDARD 99)

include_directories(linear_table)

aux_source_directory(linear_table LINEAR_TABLE_SRC)

add_executable(DataStructuresAlgorithms main.c ${LINEAR_TABLE_SRC})