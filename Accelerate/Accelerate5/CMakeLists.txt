cmake_minimum_required(VERSION 3.14)
project(Accelerate5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Accelerate5 main.cpp cmake-build-debug/array.cpp cmake-build-debug/array.h cmake-build-debug/main.h addnew.cpp addnew.h GradeBook.cpp GradeBook.h)