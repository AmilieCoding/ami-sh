# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(AMI-SH)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add source files
file(GLOB SOURCES 
    "main.c"
    "utilities/parser.c"
    "utilities/executor.c"
    "utilities/config.c"
    "builtins/builtins.c"
)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR})

# Create the executable
add_executable(ami-sh ${SOURCES})

# Link readline (must be after add_executable)
target_link_libraries(ami-sh readline)
