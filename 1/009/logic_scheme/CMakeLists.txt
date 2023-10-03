set(TARGET "logic_scheme")
project(${TARGET} LANGUAGES CXX)
add_executable(
    ${TARGET}
    logic_scheme.cpp
)
install(TARGETS ${TARGET})