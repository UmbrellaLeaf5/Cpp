cmake_minimum_required(VERSION 3.20)

set(TARGET "cell_field")

set(HEADERS
    board.h
    cell.h
    ${LIB_DIR}/Graph_lib/fltk.h
    ${LIB_DIR}/Graph_lib/Graph.h
    ${LIB_DIR}/Graph_lib/GUI.h
    ${LIB_DIR}/Graph_lib/Point.h
    ${LIB_DIR}/Graph_lib/Simple_window.h
    ${LIB_DIR}/Graph_lib/Window.h
)
set(SOURCES
    main.cpp
    cell.cpp
    board.cpp
    ${LIB_DIR}/Graph_lib/Graph.cpp
    ${LIB_DIR}/Graph_lib/GUI.cpp
    ${LIB_DIR}/Graph_lib/Window.cpp
)

project(${TARGET} CXX)

set(FLTK_SKIP_FLUID True)
set(FLTK_SKIP_FORMS True)

find_package(FLTK 1.3.8 EXACT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(SYSTEM ${FLTK_INCLUDE_DIR})
link_directories(${FLTK_INCLUDE_DIR}/../lib)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

target_link_libraries(${TARGET} ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${TARGET} fltk_jpeg fltk_png fltk_z)
endif()

install(TARGETS ${TARGET})