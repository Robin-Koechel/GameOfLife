cmake_minimum_required(VERSION 3.0)
project(gameOfLife)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(gameOfLife main.cpp Board.cpp)

# Include directory for Board.hpp
target_include_directories(gameOfLife PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
