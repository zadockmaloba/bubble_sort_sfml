cmake_minimum_required(VERSION 3.0)

project(bubble_sort_sfml)

add_executable(bubble_sort_sfml main.cpp)

install(TARGETS bubble_sort_sfml RUNTIME DESTINATION bin)
