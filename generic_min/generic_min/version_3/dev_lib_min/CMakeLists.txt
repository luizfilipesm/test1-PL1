# This must be the first command, defining minimum version for cmake.
cmake_minimum_required(VERSION 3.2)

# Define project name, version, and language
project (Lib_Minimum VERSION 1.0.0 LANGUAGES CXX)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#=== Library ===
# Inform where to look for header files.
include_directories( include )

# The project's source files.
set(SOURCES src/min.cpp)

# Lib minimum generic
add_library( mingen STATIC ${SOURCES})

set ( APP_SOURCE_DIR "app_smallest" )

# Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS mingen ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/../${APP_SOURCE_DIR}/lib)

# Also, copy the headers to the include directory of the application.
install(FILES ${CMAKE_SOURCE_DIR}/include/min.h DESTINATION ${CMAKE_SOURCE_DIR}/../${APP_SOURCE_DIR}/include )

#=== The End ===
