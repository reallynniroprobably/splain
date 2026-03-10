cmake_minimum_required(VERSION 4.2)

# ============================
# Project configuration
# ============================
project(
    splain
    VERSION 1.0
    LANGUAGES CXX
)

# ============================
# C++ standard
# ============================
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================
# Build type (optional default)
# ============================
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ============================
# Sources
# ============================
add_executable(${PROJECT_NAME}
    src/main.cpp
)


# ============================
# Compiler warnings
# ============================
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
