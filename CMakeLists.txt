cmake_minimum_required(VERSION 3.10.2)
project(bunnational)

set(PROJECT_SRC_DIR ./src)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

add_executable( bunnational
               ${PROJECT_SRC_DIR}/Book.h
               ${PROJECT_SRC_DIR}/Book.cpp
               ${PROJECT_SRC_DIR}/Library.h
               ${PROJECT_SRC_DIR}/Library.cpp
               ${PROJECT_SRC_DIR}/ScienceBook.h
               ${PROJECT_SRC_DIR}/ScienceBook.cpp )
