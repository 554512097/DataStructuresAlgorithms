set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_CPP)

add_library(cpp_lib ${DIR_CPP})