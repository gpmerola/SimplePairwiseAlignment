cmake_minimum_required(VERSION 3.10)
project(PairwiseAlignment)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(PairwiseAlignment src/main.cpp src/alignment.cpp)
