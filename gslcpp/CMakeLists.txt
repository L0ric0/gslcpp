add_library(gslcpp
    "include/gslcpp/math.hpp" "src/math.cpp"
    "include/gslcpp/poly.hpp" "src/poly.cpp"
    "include/gslcpp/util.hpp" "src/util.cpp"
    "include/gslcpp/poly/divided_difference.hpp" "src/poly/divided_difference.cpp"
    "include/gslcpp/poly/solver.hpp" "src/poly/solver.cpp"
)

target_include_directories(gslcpp PUBLIC "include")

find_package(GSL REQUIRED)
target_link_libraries(gslcpp PRIVATE GSL::gsl GSL::gslcblas)

