cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Platforma.cpp inc/Platforma.hpp src/Blocks.cpp inc/Blocks.hpp src/func.cpp inc/func.hpp Textbox.cpp Textbox.hpp)
add_executable(Project ${SOURCE_FILES} src/Platforma.cpp inc/Platforma.hpp src/Blocks.cpp inc/Blocks.hpp src/func.cpp inc/func.hpp Textbox.cpp Textbox.hpp)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Project sfml-system sfml-window sfml-graphics sfml-audio sfml-network)