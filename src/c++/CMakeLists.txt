# Specify CMAKE version 
cmake_minimum_required(VERSION 3.16.3)

# Give the project a name. CMake will automativally store this name as the variable PROJECT_NAME
project(Database)

# add_executable(${PROJECT_NAME} main.cpp) will create an executable with the same name of the project from main.cpp
add_executable(main.o main.cpp)
add_executable(testing.o testing.cpp)

