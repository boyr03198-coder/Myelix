#pragma once

#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <QString>

namespace Myelix::UI::Theme
{

    class StyleBuilderUtils final
    {
    public:
        StyleBuilderUtils() = delete;

        [[nodiscard]]
        static QString ToCss(const Myelix::Core::Theme::ThemeColor& color);

        [[nodiscard]]
        static QString Px(int value);

        [[nodiscard]]
        static QString Border(int width, const Myelix::Core::Theme::ThemeColor& color);

        [[nodiscard]]
        static QString Radius(int radius);

        [[nodiscard]]
        static QString Padding(int value);

        [[nodiscard]]
        static QString Margin(int value);

        [[nodiscard]]
        static QString FontSize(int points);

        [[nodiscard]]
        static QString FontFamily(const Myelix::Core::Theme::ThemeTypography& typography);
    };

} // namespace Myelix::UI::Theme
