# language: CMake

# ---------------------------------     Project setup      ---------------------------------
cmake_minimum_required(VERSION 3.20)

project(Cpp LANGUAGES C CXX)

# ---------------------------------    Set C++ settings    ---------------------------------
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++23 -O2")

# ---------------------------------    Add subdirectories   --------------------------------
# add_subdirectory("semesters/1/006-007/calculator")
# add_subdirectory("semesters/1/008/vec2D")
# add_subdirectory("semesters/1/009/logic_scheme")
# add_subdirectory("semesters/1/010/logic_elements")
# add_subdirectory("semesters/1/012/shape_primitives")
# add_subdirectory("semesters/1/013/fractals")
# add_subdirectory("semesters/1/014-015/Graph_lib_inheritance")
# add_subdirectory("semesters/1/018/least_squares")
# add_subdirectory("semesters/1/019/cell_field")
# add_subdirectory("semesters/1/020/chessboard")
# add_subdirectory("semesters/1/021/pointer_lesson")
add_subdirectory("semesters/1/CALCULATOR")

add_subdirectory("projects/graphic_calculator")
add_subdirectory("projects/graph")

# add_subdirectory("projects/locus_no_pilotus")
# add_subdirectory("semesters/1/022/list_lesson")
# add_subdirectory("semesters/1/023/tracer_lesson")
# add_subdirectory("semesters/1/024-025/template_lesson")
# add_subdirectory("semesters/1/027")
# add_subdirectory("semesters/2/smth/1_SFML")
add_subdirectory("semesters/3/parallel")

# add_subdirectory("semesters/4/advanced_cpp")

# add_subdirectory("template")
