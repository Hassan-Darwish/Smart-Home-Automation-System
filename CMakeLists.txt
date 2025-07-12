cmake_minimum_required(VERSION 3.16)
project(SmartHomeAutomationSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include all header directories
include_directories(include)

# Recursively collect all .cpp files under src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Add your main file if it's outside src
list(APPEND SOURCES main.cpp) 

# Create executable
add_executable(SmartHomeApp ${SOURCES})
