cmake_minimum_required(VERSION 3.13)

project(DataStructuresAlgorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(leetcode)

aux_source_directory(leetcode LEETCODE)

add_executable(DataStructuresAlgorithms ${LEETCODE} main.cpp)

#add_subdirectory(data_struct/cpp)

#target_link_libraries(DataStructuresAlgorithms cpp_lib)