#pragma once

#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <QString>

namespace CoreTheme = Myelix::Core::Theme;

namespace Myelix::UI::Theme
{

    class WidgetStyleBuilder final
    {
    public:
        [[nodiscard]]
        static QString Build(const CoreTheme::ThemePalette& palette);

    private:
        [[nodiscard]]
        static QString BuildWidgetStyle(const CoreTheme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildButtonStyle(const CoreTheme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildLineEditStyle(const CoreTheme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildLabelStyle(const CoreTheme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildMenuStyle(const CoreTheme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildStatusBarStyle(const CoreTheme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildToolTipStyle(const CoreTheme::ThemePalette& palette);
    };

} // namespace Myelix::UI::Theme
