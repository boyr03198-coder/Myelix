#include "Myelix/UI/Theme/Builders/InputStyleBuilder.hpp"

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

    QString InputStyleBuilder::ToCss(const CoreTheme::ThemeColor& color)
    {
        return CssColor(color);
    }

    QString InputStyleBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        return QString(R"(

QLineEdit,
QTextEdit,
QPlainTextEdit,
QSpinBox,
QDoubleSpinBox,
QComboBox
{
    background-color: %1;
    color: %2;
    border: 1px solid %3;
    border-radius: 4px;
    padding: %4px;
    selection-background-color: %5;
    selection-color: %6;
}

QLineEdit:focus,
QTextEdit:focus,
QPlainTextEdit:focus,
QSpinBox:focus,
QDoubleSpinBox:focus,
QComboBox:focus
{
    border: 2px solid %5;
}

QLineEdit:disabled,
QTextEdit:disabled,
QPlainTextEdit:disabled,
QSpinBox:disabled,
QDoubleSpinBox:disabled,
QComboBox:disabled
{
    background-color: %7;
    color: %8;
}

QComboBox::drop-down
{
    border: none;
    background: transparent;
}

QComboBox::down-arrow
{
    width: 10px;
    height: 10px;
}

)")
            .arg(ToCss(palette.controlBackground))   // %1
            .arg(ToCss(palette.textPrimary))         // %2
            .arg(ToCss(palette.border))              // %3
            .arg(palette.spacing.medium)             // %4
            .arg(ToCss(palette.accent))              // %5
            .arg(ToCss(palette.textInverse))         // %6
            .arg(ToCss(palette.disabledBackground))  // %7
            .arg(ToCss(palette.disabledForeground)); // %8
    }

} // namespace Myelix::UI::Theme
