# This must be the first command, defining minimum version for cmake.
cmake_minimum_required(VERSION 3.2)

# Define project name, version, and language
project (Print_Smallest VERSION 1.1.0 LANGUAGES CXX)

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

# Inform where to look for libraries.
link_directories( ${CMAKE_SOURCE_DIR}/lib )

# The project's source files.
set(SOURCES src/driver_min.cpp)

# Define which sources make the application.
add_executable( minimum ${SOURCES})

# Link the application to the library that implements the generic min().
target_link_libraries( minimum PRIVATE mingen )

#=== The End ===
