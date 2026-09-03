# Almost all CMake files should start with cmake version info
cmake_minimum_required(VERSION 3.22)

# A compatible C++ compiler that supports at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name required
project(BlackJack 
    VERSION 1.0.0 # major, minor, patch
    LANGUAGES C CXX)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(inc)