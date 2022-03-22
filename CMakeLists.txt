cmake_minimum_required(VERSION 3.23)

project(PizzaTime)
set(NAME_EXE main.cpp)

add_executable(${PROJECT_NAME} ${NAME_EXE})

add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} SRC)