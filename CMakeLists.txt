cmake_minimum_required(VERSION 3.24)
project(chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(chess main.cpp eval.cpp eval.h find.h find.cpp chess.h chess.cpp display.cpp)
