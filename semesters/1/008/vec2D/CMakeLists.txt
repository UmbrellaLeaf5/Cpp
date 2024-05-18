set(TARGET "vec2d")
project(${TARGET} LANGUAGES CXX)
add_executable(
    ${TARGET}
    vec2d.cpp
)
install(TARGETS ${TARGET})