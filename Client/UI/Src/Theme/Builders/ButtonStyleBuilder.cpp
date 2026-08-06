#include "Myelix/UI/Theme/Builders/ButtonStyleBuilder.hpp"

#include <QLatin1Char>

namespace CoreTheme = Myelix::Core::Theme;

namespace
{

    QString CssColor(const CoreTheme::ThemeColor& color)
    {
        return QString("#%1%2%3")
            .arg(color.red, 2, 16, QLatin1Char('0'))
            .arg(color.green, 2, 16, QLatin1Char('0'))
            .arg(color.blue, 2, 16, QLatin1Char('0'))
            .toUpper();
    }

} // namespace

namespace Myelix::UI::Theme
{

    QString ButtonStyleBuilder::ToCss(const CoreTheme::ThemeColor& color)
    {
        return CssColor(color);
    }

    QString ButtonStyleBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QPushButton
{
    background-color: %1;
    color: %2;
    border: 1px solid %3;
    border-radius: 6px;
    padding: %4px;
    min-height: 24px;
}

QPushButton:hover
{
    background-color: %5;
}

QPushButton:pressed
{
    background-color: %6;
}

QPushButton:disabled
{
    background-color: %7;
    color: %8;
}

QPushButton:focus
{
    border: 2px solid %5;
}

)")
            .arg(ToCss(palette.accent))
            .arg(ToCss(palette.textPrimary))
            .arg(ToCss(palette.border))
            .arg(palette.spacing.medium)
            .arg(ToCss(palette.accentHover))
            .arg(ToCss(palette.accentPressed))
            .arg(ToCss(palette.controlBackground))
            .arg(ToCss(palette.textSecondary));
    }

} // namespace Myelix::UI::Theme
