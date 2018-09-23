# This must be the first command, defining minimum version for cmake.
cmake_minimum_required(VERSION 3.2)

# Define project name, version, and language
project (Generic_Minimum VERSION 1.0.1 LANGUAGES CXX)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#=== Main App ===
# The project's source files.
set(SOURCES src/driver_min.cpp)

add_executable(minimum ${SOURCES})

#=== The End ===
