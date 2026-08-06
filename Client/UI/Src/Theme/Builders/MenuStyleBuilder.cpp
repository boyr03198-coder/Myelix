#include "Myelix/UI/Theme/Builders/MenuStyleBuilder.hpp"

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

} // anonymous namespace

namespace Myelix::UI::Theme
{

    QString MenuStyleBuilder::ToCss(const CoreTheme::ThemeColor& color)
    {
        return CssColor(color);
    }

    QString MenuStyleBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

/* ===========================
   Menu Bar
   =========================== */

QMenuBar
{
    background-color: %1;
    color: %2;
    border-bottom: 1px solid %3;
}

QMenuBar::item
{
    background: transparent;
    padding: %4px %5px;
}

QMenuBar::item:selected
{
    background-color: %6;
    color: %7;
    border-radius: 4px;
}

QMenuBar::item:disabled
{
    color: %8;
}


/* ===========================
   Menu
   =========================== */

QMenu
{
    background-color: %1;
    color: %2;
    border: 1px solid %3;
    padding: 4px;
}

QMenu::item
{
    padding: %4px %5px;
    border-radius: 4px;
}

QMenu::item:selected
{
    background-color: %6;
    color: %7;
}

QMenu::item:disabled
{
    color: %8;
    background: transparent;
}


/* ===========================
   Separators
   =========================== */

QMenu::separator
{
    height: 1px;
    background: %3;
    margin: 4px 8px;
}

)")
            .arg(ToCss(palette.panelBackground)) // %1
            .arg(ToCss(palette.textPrimary))     // %2
            .arg(ToCss(palette.border))          // %3
            .arg(palette.spacing.small)          // %4
            .arg(palette.spacing.large)          // %5
            .arg(ToCss(palette.accentHover))     // %6
            .arg(ToCss(palette.textPrimary))     // %7
            .arg(ToCss(palette.textSecondary));  // %8
    }

} // namespace Myelix::UI::Theme
