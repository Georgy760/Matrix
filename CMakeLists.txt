cmake_minimum_required(VERSION 3.23)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix main.cpp Matrix.cpp headers/Matrix.h file_reader.cpp headers/file_reader.h file_writer.cpp headers/file_writer.h gaussian_elimination.cpp headers/gaussian_elimination.h utility.cpp headers/utility.h headers/rational.h headers/rational.h rational.cpp)
