cmake_minimum_required(VERSION 3.20)

set(TARGET "link")

set(HEADERS
    link/link.h
)
set(SOURCES
    main.cpp
    link/link.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

install(TARGETS ${TARGET})