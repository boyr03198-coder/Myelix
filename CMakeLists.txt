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

option(MYELIX_BUILD_TESTS
    "Build unit tests"
    ON)

option(MYELIX_BUILD_SERVER
    "Build server components"
    OFF)

option(MYELIX_WARNINGS_AS_ERRORS
    "Treat compiler warnings as errors"
    OFF)

option(MYELIX_ENABLE_ANALYZE
    "Enable MSVC Code Analysis (/analyze)"
    OFF)

option(MYELIX_ENABLE_CLANG_TIDY
    "Enable clang-tidy"
    OFF)

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
# Compiler Options
# ============================================================================

if(MSVC)

    add_compile_options(

        # Warning level
        /W4

        # Standard conformance
        /permissive-
        /Zc:__cplusplus
        /Zc:preprocessor
        /Zc:inline
        /Zc:externConstexpr
        /Zc:wchar_t

        # Diagnostics
        /diagnostics:column

        # Security
        /sdl
        /GS

        # UTF-8
        /utf-8

        # Exceptions
        /EHsc

        # Large object files
        /bigobj

        # Parallel builds
        /MP

        # Language standard
        /std:c++20
    )

    if(MYELIX_WARNINGS_AS_ERRORS)
        add_compile_options(/WX)
    endif()

    # ------------------------------------------------------------------------
    # MSVC Static Analysis
    # ------------------------------------------------------------------------

    if(MYELIX_ENABLE_ANALYZE)

        add_compile_options(

            /analyze

            # Ignore diagnostics from external headers
            /external:anglebrackets
            /external:W0

            # Increase analysis stack
            /analyze:stacksize16384
        )

    endif()

else()

    add_compile_options(

        -Wall
        -Wextra
        -Wpedantic
    )

    if(MYELIX_WARNINGS_AS_ERRORS)
        add_compile_options(-Werror)
    endif()

endif()

# ============================================================================
# clang-tidy
# ============================================================================

if(MYELIX_ENABLE_CLANG_TIDY)

    find_program(CLANG_TIDY_EXE
        NAMES clang-tidy)

    if(CLANG_TIDY_EXE)

        set(CMAKE_CXX_CLANG_TIDY
            ${CLANG_TIDY_EXE}
            -p=${CMAKE_BINARY_DIR})

        message(STATUS "clang-tidy enabled")

    else()

        message(FATAL_ERROR
            "MYELIX_ENABLE_CLANG_TIDY is ON but clang-tidy was not found.")

    endif()

endif()

# ============================================================================
# Linker Security & Optimization
# ============================================================================

if(MSVC)

    add_link_options(

        # Security
        /DYNAMICBASE
        /NXCOMPAT
        /GUARD:CF
        /HIGHENTROPYVA

        # Debug
        $<$<CONFIG:Debug>:/INCREMENTAL>

        # Release
        $<$<CONFIG:Release>:/OPT:REF>
        $<$<CONFIG:Release>:/OPT:ICF>
        $<$<CONFIG:Release>:/LTCG>
    )

endif()

# ============================================================================
# Runtime Library
# ============================================================================

if(MSVC)

    set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

endif()

# ============================================================================
# Testing
# ============================================================================

include(CTest)

# ============================================================================
# Modules
# ============================================================================

if(EXISTS "${CMAKE_SOURCE_DIR}/Client/CMakeLists.txt")
    add_subdirectory(Client)
endif()

if(MYELIX_BUILD_SERVER
   AND EXISTS "${CMAKE_SOURCE_DIR}/Server/CMakeLists.txt")
    add_subdirectory(Server)
endif()

if(MYELIX_BUILD_TESTS
   AND EXISTS "${CMAKE_SOURCE_DIR}/Tests/CMakeLists.txt")
    add_subdirectory(Tests)
endif()

# ============================================================================
# Configuration Summary
# ============================================================================

message(STATUS "")
message(STATUS "========================================")
message(STATUS "Configuring Myelix ${PROJECT_VERSION}")
message(STATUS "========================================")
message(STATUS "C++ Standard        : ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler            : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Warnings as Errors  : ${MYELIX_WARNINGS_AS_ERRORS}")
message(STATUS "MSVC /analyze       : ${MYELIX_ENABLE_ANALYZE}")
message(STATUS "clang-tidy          : ${MYELIX_ENABLE_CLANG_TIDY}")
message(STATUS "Build Tests         : ${MYELIX_BUILD_TESTS}")
message(STATUS "Build Server        : ${MYELIX_BUILD_SERVER}")
message(STATUS "========================================")
message(STATUS "")
