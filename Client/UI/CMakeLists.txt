# ============================================================================
# Myelix UI Module
# ============================================================================

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
)

add_library(MyelixUI STATIC)

target_sources(MyelixUI
    PRIVATE
        Src/Theme/Builders/ThemeEngine.cpp
        Src/Theme/Builders/ButtonStyleBuilder.cpp
        Src/Theme/Builders/StyleSheetBuilder.cpp
        Src/Theme/Builders/WidgetStyleBuilder.cpp
        Src/Theme/Builders/InputStyleBuilder.cpp
        Src/Theme/Builders/MenuStyleBuilder.cpp
        Src/Theme/Builders/ViewStyleBuilder.cpp
        Src/Theme/Builders/ScrollBarStyleBuilder.cpp
        Src/Theme/Builders/ToolTipStyleBuilder.cpp
        Src/Theme/Builders/CheckBoxStyleBuilder.cpp
        Src/Theme/Builders/StyleBuilderUtils.cpp
        Src/Theme/Builders/RadioButtonStyleBuilder.cpp
        Src/Theme/Builders/ComboBoxStyleBuilder.cpp
        Src/Theme/Builders/SpinBoxStyleBuilder.cpp
        Src/Theme/Builders/SliderStyleBuilder.cpp
        Src/Theme/Builders/GroupBoxStyleBuilder.cpp
        Src/Theme/Builders/TabStyleBuilder.cpp
        Src/Theme/Builders/DockWidgetStyleBuilder.cpp
        Src/Theme/Builders/ToolBarStyleBuilder.cpp
        Src/Theme/Builders/ProgressBarStyleBuilder.cpp
        Src/Theme/Builders/PropertyGridStyleBuilder.cpp
        Src/Theme/Builders/RibbonStyleBuilder.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS Include
        FILES
            Include/Myelix/UI/Theme/Builders/ThemeEngine.hpp
            Include/Myelix/UI/Theme/Builders/ButtonStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/StyleSheetBuilder.hpp
            Include/Myelix/UI/Theme/Builders/WidgetStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/InputStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/MenuStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/ViewStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/ScrollBarStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/ToolTipStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/CheckBoxStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp
            Include/Myelix/UI/Theme/Builders/RadioButtonStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/ComboBoxStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/SpinBoxStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/SliderStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/GroupBoxStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/TabStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/DockWidgetStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/ToolBarStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/ProgressBarStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/PropertyGridStyleBuilder.hpp
            Include/Myelix/UI/Theme/Builders/RibbonStyleBuilder.hpp

           )

target_link_libraries(MyelixUI
    PUBLIC
        MyelixCore
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

target_compile_features(MyelixUI
    PUBLIC
        cxx_std_20
)

target_include_directories(MyelixUI
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)
