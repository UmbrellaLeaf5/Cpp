cmake_minimum_required(VERSION 3.20)

set(TARGET "1_SFML")

set(SOURCES
  main.cpp
)

project(${TARGET} LANGUAGES CXX)

if(LINUX)
  set(SFML_STATIC_LIBRARIES FALSE)
else()
  set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML COMPONENTS graphics REQUIRED)

# find_package(OpenGL REQUIRED)
include_directories(SYSTEM ${SFML_INCLUDE_DIR})

add_executable(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} sfml-graphics)

install(TARGETS ${TARGET})