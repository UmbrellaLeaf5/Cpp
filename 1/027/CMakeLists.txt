cmake_minimum_required(VERSION 3.20)

set(TARGET "RAII_lesson")

set(HEADERS
    ${LIB_DIR}/Tracer_lib/tracer.h
)
set(SOURCES
    main.cpp
    ${LIB_DIR}/Tracer_lib/tracer.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

install(TARGETS ${TARGET})