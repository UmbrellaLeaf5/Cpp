cmake_minimum_required(VERSION 3.20)

set(TARGET "calculator")

project(${TARGET} LANGUAGES CXX)

add_executable(
    ${TARGET}
    calculator.cpp
    main_grammar_functions.cpp
    Names.cpp
    Token.cpp
    calculator_globals.cpp
)

install(TARGETS ${TARGET})