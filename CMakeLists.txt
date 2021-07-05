cmake_minimum_required(VERSION 3.12) # inimum required CMAKE version
project(Database) # Name of project stored in PROJECT_NAME

# Create library for IO code
# add_library(IO ./src/c++/IO/io.cpp ./include/io.h)
# add_subdirectory(./src/c++/IO)

# Create executable tsarget
SET(MAIN_APP "MainApp")
add_executable(${MAIN_APP} ./src/c++/main.cpp ./src/c++/IO/io.cpp)
# target_link_libraries(${MAIN_APP} IO) # link IO library to this target
target_include_directories(${MAIN_APP} PUBLIC ./include)

SET(TEST_APP "TestApp")
add_executable(${TEST_APP} ./src/c++/testing.cpp)


