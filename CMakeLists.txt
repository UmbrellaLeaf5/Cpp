set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")
cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(
    ${LIB_DIR}
)
#add_subdirectory("1/006-007/calculator")
#add_subdirectory("1/008/vec2D")
#add_subdirectory("1/009/logic_scheme")
add_subdirectory("1/010/logic_elements")