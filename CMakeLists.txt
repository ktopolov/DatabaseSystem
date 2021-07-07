cmake_minimum_required(VERSION 3.12) # inimum required CMAKE version
project(Tensor) # Name of project stored in PROJECT_NAME

# Create executable tsarget
SET(LEARN "Learn")
add_executable(${LEARN} ./src/learn.cpp)
target_include_directories(${LEARN} PUBLIC ./include)

SET(EVAL "Eval")
add_executable(${EVAL} ./src/eval.cpp)
target_include_directories(${EVAL} PUBLIC ./include)

