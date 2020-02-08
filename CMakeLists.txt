cmake_minimum_required(VERSION 3.10)

project(SpaceCombat)

add_subdirectory("Source")
include_directories("Source")
include_directories("Include")

add_executable(SpaceCombat Source/main.cpp)
