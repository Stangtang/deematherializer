cmake_minimum_required(VERSION 3.20)

project(DEEMATHERIALIZER VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find all implementation files in src/.
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

# Headers
target_include_directories(DEEMATHERIALIZER
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Enable useful warnings.
if(MSVC)
    target_compile_options(DEEMATHERIALIZER PRIVATE /W4 /permissive-)
else()
    target_compile_options(DEEMATHERIALIZER PRIVATE -Wall -Wextra -Wpedantic)
endif()

