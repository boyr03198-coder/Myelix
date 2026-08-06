# ============================================================================
# Myelix Security Module
# ============================================================================

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(MyelixSecurity STATIC)

target_sources(MyelixSecurity
    PRIVATE
        Src/SecurityModule.cpp
        Src/SecurityManager.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS Include
        FILES
            Include/Myelix/Security/SecurityModule.hpp
            Include/Myelix/Security/SecurityLevel.hpp
            Include/Myelix/Security/SecurityEvent.hpp
            Include/Myelix/Security/SecurityManager.hpp
)

target_link_libraries(MyelixSecurity
    PUBLIC
        MyelixCore
        Qt6::Core
)

target_compile_features(MyelixSecurity
    PUBLIC
        cxx_std_20
)

target_include_directories(MyelixSecurity
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

set_target_properties(MyelixSecurity
    PROPERTIES
        FOLDER "Client"
)
