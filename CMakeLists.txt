cmake_minimum_required(VERSION 3.10)

project(SpaceCombat)

include_directories(SFML/include)
include_directories("Include")
add_subdirectory("Source")
link_directories(SFML/lib)

add_executable(SpaceCombat ${SOURCES})

target_link_libraries(SpaceCombat sfml-main sfml-system sfml-window sfml-graphics)
