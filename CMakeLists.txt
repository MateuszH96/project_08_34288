cmake_minimum_required(VERSION 3.23)

project(PizzaTime)
set(NAME_EXE main.cpp)

add_executable(${PROJECT_NAME} ${NAME_EXE})

add_subdirectory(src)
add_compile_options(-Og -ggdb -fsanitize=address -lasan)
target_link_libraries(${PROJECT_NAME} SRC)