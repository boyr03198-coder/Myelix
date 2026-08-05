# ============================================================================
# Myelix Application
# ============================================================================

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
)

qt_standard_project_setup()

qt_add_executable(MyelixApp
    WIN32
    Src/main.cpp
    Src/MainWindow.cpp
    Include/Myelix/App/MainWindow.hpp
)

target_include_directories(MyelixApp
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_link_libraries(MyelixApp
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

target_compile_features(MyelixApp
    PRIVATE
        cxx_std_20
)

set_target_properties(MyelixApp
    PROPERTIES
        OUTPUT_NAME "Myelix"
)
