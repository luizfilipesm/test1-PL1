# This must be the first command, defining minimum version for cmake.
cmake_minimum_required(VERSION 3.2)

# Define project name, version, and language
project (Generic_Minimum VERSION 1.0.0 LANGUAGES CXX)

# Define C++11 as the standard for this project.
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
# Append this flag to the flags already defined.
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#=== Main App ===
# The app has only one source file.
add_executable(minimum src/driver_min.cpp)
