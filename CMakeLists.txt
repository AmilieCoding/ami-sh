# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(AMI-SH)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add source files and include subdirectories
# Here we add the subfolders with source files (e.g., utilities and builtins)
file(GLOB SOURCES 
    "main.c"
    "utilities/parser.c"
    "utilities/executor.c"
    "builtins/builtins.c"
)

# Add include directories (if necessary)
# Here we include the current directory so the header files can be found
include_directories(${CMAKE_SOURCE_DIR})

# Create the executable
add_executable(ami-sh ${SOURCES})
