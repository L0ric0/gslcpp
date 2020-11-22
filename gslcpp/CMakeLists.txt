add_library(gslcpp
    src/math.cpp
    src/poly.cpp
    src/util.cpp)

target_include_directories(gslcpp PUBLIC "include")

find_package(GSL REQUIRED)
target_link_libraries(gslcpp PRIVATE GSL::gsl GSL::gslcblas)

