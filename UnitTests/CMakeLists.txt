cmake_minimum_required(VERSION 2.6)
 

set(This UnitTests)
project(${This})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(Source
    ../src/ReadFile.cpp
    ../src/PrintFromFile.cpp
    ../src/MenuPos.cpp
    ../src/Order.cpp
    ../src/OrderPos.cpp
    ../src/PrintMenu.cpp)

add_executable(${This} UnitTests.cpp ${Source})
target_link_libraries(${This} ${GTEST_LIBRARIES} pthread)
