cmake_minimum_required(VERSION 3.12) # inimum required CMAKE version
project(Tensor) # Name of project stored in PROJECT_NAME

# Ensure libraries are built
add_subdirectory(./src/Parse) # add Parse library directory

# Create Learn executable target
SET(LEARN "Learn")
add_executable(${LEARN} ./src/learn.cpp)
target_link_libraries(${LEARN} PUBLIC Parse)  # link to .lib file
target_include_directories(${LEARN} PUBLIC ./src/Parse)  # show target where functions in Parse are declared

# Create Eval target
SET(EVAL "Eval")
add_executable(${EVAL} ./src/eval.cpp)
target_include_directories(${EVAL} PUBLIC ./include)

