cmake_minimum_required(VERSION 3.20)

set(TARGET "calculator")

project(${TARGET} LANGUAGES CXX)

set(FLTK_SKIP_FLUID True)
set(OpenGL_GL_PREFERENCE "GLVND")

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    SYSTEM
)

add_executable(
    ${TARGET}
    calculator.cpp
    main_grammar_functions.cpp
    Names.cpp
    Token.cpp

)

target_link_libraries(
    ${TARGET}
)

install(TARGETS ${TARGET})