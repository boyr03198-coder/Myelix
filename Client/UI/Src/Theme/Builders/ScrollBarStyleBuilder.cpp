#include "Myelix/UI/Theme/Builders/ScrollBarStyleBuilder.hpp"


#include <QLatin1Char>

namespace CoreTheme = Myelix::Core::Theme;

namespace
{

    QString ToCss(const CoreTheme::ThemeColor& color)
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

    QString ScrollBarStyleBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

/* ============================================================
   Vertical ScrollBar
   ============================================================ */

QScrollBar:vertical
{
    background:%1;
    width:14px;
    margin:0px;
}

QScrollBar::handle:vertical
{
    background:%2;
    min-height:30px;
    border-radius:6px;
}

QScrollBar::handle:vertical:hover
{
    background:%3;
}

QScrollBar::handle:vertical:pressed
{
    background:%4;
}

QScrollBar::add-line:vertical,
QScrollBar::sub-line:vertical
{
    height:0px;
}

QScrollBar::add-page:vertical,
QScrollBar::sub-page:vertical
{
    background:transparent;
}

/* ============================================================
   Horizontal ScrollBar
   ============================================================ */

QScrollBar:horizontal
{
    background:%1;
    height:14px;
    margin:0px;
}

QScrollBar::handle:horizontal
{
    background:%2;
    min-width:30px;
    border-radius:6px;
}

QScrollBar::handle:horizontal:hover
{
    background:%3;
}

QScrollBar::handle:horizontal:pressed
{
    background:%4;
}

QScrollBar::add-line:horizontal,
QScrollBar::sub-line:horizontal
{
    width:0px;
}

QScrollBar::add-page:horizontal,
QScrollBar::sub-page:horizontal
{
    background:transparent;
}

)")
            .arg(ToCss(palette.panelBackground))
            .arg(ToCss(palette.border))
            .arg(ToCss(palette.accentHover))
            .arg(ToCss(palette.accentPressed));
    }

} // namespace Myelix::UI::Theme
