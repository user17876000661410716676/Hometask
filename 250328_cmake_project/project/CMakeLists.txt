cmake_minimum_required(VERSION 3.16)

project(250328_cmake_project)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(universities_list)
add_subdirectory(insertion_sort)
add_subdirectory(long_number)
add_subdirectory(vector)
add_subdirectory(doubly_linked_list)

set(CMAKE_SUPPRESS_REGENERATION True)