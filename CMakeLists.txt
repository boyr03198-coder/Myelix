cmake_minimum_required(VERSION 3.25)

# ============================================================================
# Myelix
# Enterprise Native Windows AI Assistant
# ============================================================================

project(
    Myelix
    VERSION 0.1.0
    DESCRIPTION "Myelix Native Windows AI Assistant"
    LANGUAGES CXX
)

# ============================================================================
# Global Project Settings
# ============================================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ============================================================================
# Qt Automatic Processing
# ============================================================================

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ============================================================================
# Build Options
# ============================================================================

option(MYELIX_BUILD_TESTS "Build unit tests" ON)
option(MYELIX_BUILD_SERVER "Build server components" OFF)

# ============================================================================
# Output Directories
# ============================================================================

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib)

# ============================================================================
# Compiler Warnings
# ============================================================================

if (MSVC)
    add_compile_options(
        /W4
        /permissive-
        /Zc:__cplusplus
    )
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# ============================================================================
# Testing
# ============================================================================

include(CTest)

# ============================================================================
# Modules
# ============================================================================

if (EXISTS "${CMAKE_SOURCE_DIR}/Client/CMakeLists.txt")
    add_subdirectory(Client)
endif()

if (MYELIX_BUILD_SERVER AND EXISTS "${CMAKE_SOURCE_DIR}/Server/CMakeLists.txt")
    add_subdirectory(Server)
endif()

if (MYELIX_BUILD_TESTS AND EXISTS "${CMAKE_SOURCE_DIR}/Tests/CMakeLists.txt")
    add_subdirectory(Tests)
endif()

message(STATUS "Configuring Myelix ${PROJECT_VERSION}")
