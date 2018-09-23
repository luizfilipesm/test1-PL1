# This must be the first command, defining minimum version for cmake.
cmake_minimum_required(VERSION 3.2)

# Define project name, version, and language
project (Sort_Ranges VERSION 1.0.0 LANGUAGES CXX)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )


#=== The app ===
# Inform where to look for header files.
include_directories( include )

# The project's source files.
set(SOURCES src/driver_sort.cpp)

# Define which sources make the application.
add_executable( sort_ranges ${SOURCES})

#=== The End ===
