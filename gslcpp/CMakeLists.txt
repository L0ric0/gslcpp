file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(gslcpp ${SOURCES})

target_include_directories(gslcpp PUBLIC "include")

find_package(GSL REQUIRED)
target_link_libraries(gslcpp PRIVATE GSL::gsl GSL::gslcblas)

