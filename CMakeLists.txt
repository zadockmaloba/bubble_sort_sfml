cmake_minimum_required(VERSION 3.0)

project(bubble_sort_sfml)

add_executable(bubble_sort_sfml main.cpp)

find_package(SFML COMPONENTS graphics audio window system REQUIRED)
target_link_libraries(bubble_sort_sfml sfml-graphics sfml-audio sfml-window sfml-system)

install(TARGETS bubble_sort_sfml RUNTIME DESTINATION bin)
