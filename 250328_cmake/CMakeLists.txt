cmake_minimum_required(VERSION 3.10)

project(UniversitiesList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_EXE functions.cpp main.cpp menu_fragments.cpp)
set(HEADER structs.hpp functions.hpp menu_fragments.hpp)

add_executable(main ${SOURCE_EXE})