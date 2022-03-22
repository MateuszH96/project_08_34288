cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
set(This UnitTests)
project(${This})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(Source
    ../src/ReadFile.cpp
    ../src/PrintFromFile.cpp
    ../src/Ingredient.cpp)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src)
# Link runTests with what we want to test and the GTest and pthread library
add_executable(${This} UnitTests.cpp ${Source})
target_link_libraries(${This} ${GTEST_LIBRARIES} pthread)
