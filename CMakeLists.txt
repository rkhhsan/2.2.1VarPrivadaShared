cmake_minimum_required(VERSION 3.17)
project(2.2.1VarPrivadaShared)

add_executable(2.2.1VarPrivadaShared vpc.cpp)

# Acesso ao GSL-GNU
# target_link_libraries (2.2.1VarPrivadaShared -lgsl -lgslcblas -lm)

# Acesso ao OpenMP
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")
set (SOURCE_FILES vpc.cpp)
# add_executable(openmp_test_clion ${SOURCE_FILES})