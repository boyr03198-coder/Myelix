#pragma once

#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <QString>

namespace CoreTheme = Myelix::Core::Theme;

namespace Myelix::UI::Theme
{

    class InputStyleBuilder final
    {
    public:
        [[nodiscard]]
        static QString Build(const CoreTheme::ThemePalette& palette);

    private:
        [[nodiscard]]
        static QString ToCss(const CoreTheme::ThemeColor& color);
    };

} // namespace Myelix::UI::Theme
