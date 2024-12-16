cmake_minimum_required(VERSION 3.15)
project(OpenXROverlay)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add OpenXR SDK headers
include_directories(${CMAKE_SOURCE_DIR}/libs/OpenXR-SDK/include)

# Find and link the OpenXR loader library
find_library(OPENXR_LOADER_LIB openxr_loader PATHS ${CMAKE_SOURCE_DIR}/libs/OpenXR-SDK/lib)

if(NOT OPENXR_LOADER_LIB)
    message(FATAL_ERROR "OpenXR Loader library not found!")
endif()

# Add source files
add_executable(OpenXROverlay src/main.cpp)

# Link OpenXR loader
target_link_libraries(OpenXROverlay ${OPENXR_LOADER_LIB})
