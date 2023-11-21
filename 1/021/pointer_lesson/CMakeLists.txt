cmake_minimum_required(VERSION 3.20)

set(TARGET "pointer_lesson")

set(HEADERS
    my_sort.h
    str_oper.h
)
set(SOURCES
    main.cpp
    my_sort.cpp
    str_oper.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

install(TARGETS ${TARGET})