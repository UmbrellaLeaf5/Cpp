set(TARGET "calculator")
project(${TARGET} LANGUAGES CXX)
add_executable(
    ${TARGET}
    calculator08buggy.cpp
)
install(TARGETS ${TARGET})