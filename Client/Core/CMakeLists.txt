# ============================================================================
# Myelix Core Module
# ============================================================================

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(MyelixCore STATIC)

target_sources(MyelixCore
    PRIVATE
        Src/CoreModule.cpp
        Src/Logging/Logger.cpp
        Src/Theme/ThemeManager.cpp
        Src/Settings/SettingsManager.cpp
        Src/Theme/SystemThemeWatcher.cpp
        Src/Theme/AccentColorProvider.cpp
        Src/Theme/ThemeColor.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            Include
        FILES
            Include/Myelix/Core/CoreModule.hpp

            Include/Myelix/Core/Logging/Logger.hpp
            Include/Myelix/Core/Logging/LogLevel.hpp
            Include/Myelix/Core/Logging/LogMessage.hpp

            Include/Myelix/Core/Theme/Theme.hpp
            Include/Myelix/Core/Theme/ThemeColor.hpp
            Include/Myelix/Core/Theme/ThemeSpacing.hpp
            Include/Myelix/Core/Theme/ThemeTypography.hpp
            Include/Myelix/Core/Theme/ThemePalette.hpp
            Include/Myelix/Core/Theme/ThemeManager.hpp
            Include/Myelix/Core/Theme/SystemThemeWatcher.hpp

            Include/Myelix/Core/Settings/SettingsKeys.hpp
            Include/Myelix/Core/Settings/SettingsManager.hpp
            Include/Myelix/Core/Theme/AccentColorProvider.hpp
)

target_link_libraries(MyelixCore
    PUBLIC
        Qt6::Core
)

target_compile_features(MyelixCore
    PUBLIC
        cxx_std_20
)

target_include_directories(MyelixCore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

set_target_properties(MyelixCore PROPERTIES
    AUTOMOC OFF
    AUTOUIC OFF
    AUTORCC OFF
)
