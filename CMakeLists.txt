cmake_minimum_required(VERSION 3.20)

# Project name and language used by this project.
project(DEEMATHERIALIZER
    VERSION 1.0.0
    LANGUAGES CXX
)

# Use the C++20 standard for every target in this project.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Prefer standard C++ over compiler-specific extensions.

# Find all implementation files in src/.
# CONFIGURE_DEPENDS asks CMake to re-check this directory when files are added
# or removed, which keeps this beginner-friendly layout convenient to use.
file(GLOB_RECURSE DEEMATHERIALIZER_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx"
)

# Build the application from main.cpp and the implementation files in src/.
add_executable(DEEMATHERIALIZER
    main.cpp
    ${DEEMATHERIALIZER_SOURCES}
)

# Tell the compiler where to find headers included by the source files.
target_include_directories(DEEMATHERIALIZER
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Enable useful warnings. The options are kept compiler-specific so the same
# CMake file works with both MSVC and GCC/Clang-style compilers.
if(MSVC)
    target_compile_options(DEEMATHERIALIZER PRIVATE /W4 /permissive-)
else()
    target_compile_options(DEEMATHERIALIZER PRIVATE -Wall -Wextra -Wpedantic)
endif()

