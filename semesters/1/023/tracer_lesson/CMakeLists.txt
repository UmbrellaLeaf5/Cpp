cmake_minimum_required(VERSION 3.20)

set(TARGET "tracer")

set(HEADERS
    ${LIB_DIR}/Tracer_lib/tracer.h
)
set(SOURCES
    main.cpp
    ${LIB_DIR}/Tracer_lib/tracer.cpp
)

project(${TARGET} CXX)

add_definitions(
    -DENABLE_TRACING
)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

install(TARGETS ${TARGET})