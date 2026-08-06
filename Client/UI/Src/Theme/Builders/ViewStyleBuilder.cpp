#include "Myelix/UI/Theme/Builders/ViewStyleBuilder.hpp"

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

    QString ViewStyleBuilder::ToCss(const CoreTheme::ThemeColor& color)
    {
        return CssColor(color);
    }

    QString ViewStyleBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

/* ===========================================================
   QListView
   =========================================================== */

QListView
{
    background-color: %1;
    color: %2;
    border: 1px solid %3;
    outline: none;
}

QListView::item
{
    padding: %4px;
}

QListView::item:selected
{
    background-color: %5;
    color: %2;
}

QListView::item:hover
{
    background-color: %6;
}


/* ===========================================================
   QTreeView
   =========================================================== */

QTreeView
{
    background-color: %1;
    color: %2;
    border: 1px solid %3;
    alternate-background-color: %7;
    outline: none;
}

QTreeView::item
{
    padding: %4px;
}

QTreeView::item:selected
{
    background-color: %5;
    color: %2;
}

QTreeView::item:hover
{
    background-color: %6;
}


/* ===========================================================
   QTableView
   =========================================================== */

QTableView
{
    background-color: %1;
    color: %2;
    border: 1px solid %3;
    gridline-color: %3;
    alternate-background-color: %7;
    selection-background-color: %5;
    selection-color: %2;
}

QTableView::item
{
    padding: %4px;
}


/* ===========================================================
   Header View
   =========================================================== */

QHeaderView::section
{
    background-color: %7;
    color: %2;
    border: 1px solid %3;
    padding: %4px;
    font-weight: bold;
}

)")
            .arg(ToCss(palette.controlBackground)) // %1
            .arg(ToCss(palette.textPrimary))       // %2
            .arg(ToCss(palette.border))            // %3
            .arg(palette.spacing.small)            // %4
            .arg(ToCss(palette.accent))            // %5
            .arg(ToCss(palette.accentHover))       // %6
            .arg(ToCss(palette.panelBackground));  // %7
    }

} // namespace Myelix::UI::Theme
