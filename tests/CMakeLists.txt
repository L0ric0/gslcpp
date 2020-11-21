set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

target_include_directories(${BINARY} PRIVATE include)

find_package(GTest REQUIRED)
target_link_libraries(${BINARY} PRIVATE GTest::GTest GTest::Main)

target_link_libraries(${BINARY} PRIVATE gslcpp)

gtest_discover_tests(${BINARY})
