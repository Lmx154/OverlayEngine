cmake_minimum_required(VERSION 3.15)
project(HelloXR)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Platform-independent sources
set(SRC
        src/main.cpp
        src/openxr_program.cpp
)

# Android-specific configuration
if (ANDROID)
    # Add Android-specific source files
    set(SRC ${SRC}
            src/platform/android/android_main.cpp
            src/platform/android/android_native_app_glue.c
    )

    # Build a shared library for Android
    add_library(native-lib SHARED ${SRC})

    # Include directories
    include_directories(
            ${CMAKE_SOURCE_DIR}/libs/OpenXR-SDK/include
    )

    # Define path to OpenXR loader
    set(OPENXR_LOADER ${CMAKE_SOURCE_DIR}/libs/OpenXR-SDK/lib/libopenxr_loader.so)

    # Link libraries
    target_link_libraries(native-lib
            ${OPENXR_LOADER}  # Link to OpenXR loader
            android
            log
            EGL
    )
else()
    # Add fallback for non-Android builds (optional)
    add_executable(hello_xr ${SRC})
endif()
