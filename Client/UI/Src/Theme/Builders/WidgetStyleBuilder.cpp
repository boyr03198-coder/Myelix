#include "Myelix/UI/Theme/Builders/WidgetStyleBuilder.hpp"

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

    QString WidgetStyleBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        QString style;

        style += BuildWidgetStyle(palette);
        style += BuildButtonStyle(palette);
        style += BuildLineEditStyle(palette);
        style += BuildLabelStyle(palette);
        style += BuildMenuStyle(palette);
        style += BuildStatusBarStyle(palette);
        style += BuildToolTipStyle(palette);

        return style;
    }

    QString WidgetStyleBuilder::BuildWidgetStyle(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QWidget
{
    background-color:%1;
    color:%2;
    font-family:"%3";
    font-size:%4pt;
}

QMainWindow
{
    background-color:%1;
}

)")
            .arg(ToCss(palette.windowBackground))
            .arg(ToCss(palette.textPrimary))
            .arg(QString::fromStdString(palette.typography.family))
            .arg(palette.typography.normalSize);
    }

    QString WidgetStyleBuilder::BuildButtonStyle(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QPushButton
{
    background-color:%1;
    color:%2;
    border:1px solid %3;
    border-radius:6px;
    padding:%4px;
}

QPushButton:hover
{
    background-color:%5;
}

QPushButton:pressed
{
    background-color:%6;
}

QPushButton:disabled
{
    background-color:%7;
    color:%8;
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

    QString WidgetStyleBuilder::BuildLineEditStyle(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QLineEdit
{
    background-color:%1;
    color:%2;
    border:1px solid %3;
    border-radius:4px;
    padding:%4px;
}

QLineEdit:focus
{
    border:1px solid %5;
}

)")
            .arg(ToCss(palette.controlBackground))
            .arg(ToCss(palette.textPrimary))
            .arg(ToCss(palette.border))
            .arg(palette.spacing.medium)
            .arg(ToCss(palette.accent));
    }

    QString WidgetStyleBuilder::BuildLabelStyle(const CoreTheme::ThemePalette&)
    {
        return QString(R"(

QLabel
{
    color:palette(window-text);
}

)");
    }

    QString WidgetStyleBuilder::BuildMenuStyle(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QMenuBar
{
    background-color:%1;
    color:%2;
}

QMenuBar::item:selected
{
    background-color:%3;
}

QMenu
{
    background-color:%1;
    color:%2;
    border:1px solid %4;
}

QMenu::item:selected
{
    background-color:%3;
}

)")
            .arg(ToCss(palette.windowBackground))
            .arg(ToCss(palette.textPrimary))
            .arg(ToCss(palette.accent))
            .arg(ToCss(palette.border));
    }

    QString WidgetStyleBuilder::BuildStatusBarStyle(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QStatusBar
{
    background-color:%1;
    color:%2;
}

)")
            .arg(ToCss(palette.windowBackground))
            .arg(ToCss(palette.textPrimary));
    }

    QString WidgetStyleBuilder::BuildToolTipStyle(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QToolTip
{
    background-color:%1;
    color:%2;
    border:1px solid %3;
}

)")
            .arg(ToCss(palette.controlBackground))
            .arg(ToCss(palette.textPrimary))
            .arg(ToCss(palette.border));
    }

} // namespace Myelix::UI::Theme
