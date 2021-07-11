cmake_minimum_required(VERSION 3.12) # inimum required CMAKE version
project(BankDatabase) # Name of project stored in PROJECT_NAME

# Ensure libraries are built
add_subdirectory(./src/Parse) # add Parse library directory

# Create Learn executable target
SET(ACCESS "Access")
add_executable(${ACCESS} ./src/access.cpp)  # allows adding/removing
target_link_libraries(${ACCESS} PUBLIC Parse)  # link to .lib file
target_include_directories(${ACCESS} PUBLIC ./src/Parse)  # show target where functions in Parse are declared

# Create Eval target
# SET(EVAL "Eval")
# add_executable(${EVAL} ./src/eval.cpp)
# target_include_directories(${EVAL} PUBLIC ./include)
# 
