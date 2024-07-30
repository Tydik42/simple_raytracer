cmake_minimum_required(VERSION 3.20)
project(simple_raytracer)
add_executable (${PROJECT_NAME} main.cpp)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/core/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/core/include)


file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/core/src/*.cpp")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})


# Set C++ standard
set(CMAKE_CXX_STANDARD 20)


# Set compiler options
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -pedantic)


