cmake_minimum_required(VERSION 3.10)

project(SpaceCombat)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(SFML/include)
include_directories("Include")
add_subdirectory("Source")
link_directories(SFML/lib)

add_executable(SpaceCombat ${SOURCES})

target_link_libraries(SpaceCombat sfml-main sfml-system sfml-window sfml-graphics)
