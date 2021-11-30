# Specify CMAKE version 
cmake_minimum_required(VERSION 3.16.3)

# Give the project a name. CMake will automativally store this name as the variable PROJECT_NAME
project(Database)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(matrix ${PROJECT_SOURCE_DIR}/include/math/Matrix.h ${PROJECT_SOURCE_DIR}/src/math/Matrix.cpp)
# add_executable(${PROJECT_NAME} main.cpp) will create an executable with the same name of the project from main.cpp
add_executable(matrix_test ${PROJECT_SOURCE_DIR}/tests/matrix_test.cpp)
target_link_libraries(matrix_test matrix)

# add_executable(matrix_test ${PROJECT_SOURCE_DIR}/tests/matrix_test.cpp ${PROJECT_SOURCE_DIR}/include/math/Matrix.h ${PROJECT_SOURCE_DIR}/src/math/Matrix.cpp)
