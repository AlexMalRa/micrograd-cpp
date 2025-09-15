cmake_minimum_required(VERSION 3.15) # Set minimum CMake version
project(micrograd LANGUAGES CXX) # Define project name and language

set(CMAKE_CXX_STANDARD 20) # Set C++ standard to C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Enforce C++20 standard

# Library
add_library(micrograd src/Value.cpp) # Create static library from source file
target_include_directories(micrograd PUBLIC include) # Specify include directories for the library

# Executable
add_executable(micrograd_app src/main.cpp) # Create executable from main source file
target_link_libraries(micrograd_app PRIVATE micrograd) # Link the library to the executable
