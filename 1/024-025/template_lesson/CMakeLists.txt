cmake_minimum_required(VERSION 3.20)

set(TARGET "template_lesson")

set(HEADERS
    unique_ptr/unique.h
    counted_ptr/counted.h
    E_testing/E.h
    ${LIB_DIR}/Tracer_lib/tracer.h
)
set(SOURCES
    main.cpp
    E_testing/E.cpp
    ${LIB_DIR}/Tracer_lib/tracer.cpp
)

project(${TARGET} CXX)

add_definitions(
    -DENABLE_TRACING
)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

install(TARGETS ${TARGET})