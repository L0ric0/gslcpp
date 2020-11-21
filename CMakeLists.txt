cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

project(gslcpp VERSION 0.0.1)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "gslcpp/src/*.cpp")

add_library(gslcpp ${SOURCES})

target_include_directories(gslcpp PUBLIC "gslcpp/include")

find_package(GSL REQUIRED)
target_link_libraries(gslcpp PRIVATE GSL::gsl GSL::gslcblas)

### TESTS ###
add_subdirectory(tests)

### DOCS ###
find_package(Doxygen)

doxygen_add_docs(doc ALL WORKING_DIRECTORY gslcpp)
