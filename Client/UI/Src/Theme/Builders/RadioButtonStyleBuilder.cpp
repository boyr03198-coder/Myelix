#include "Myelix/UI/Theme/Builders/RadioButtonStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString RadioButtonStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        return QString(R"(

QRadioButton
{
    color: %1;
    spacing: %2px;
}

QRadioButton:disabled
{
    color: %3;
}

QRadioButton::indicator
{
    width: 16px;
    height: 16px;

    border: %4;
    border-radius: 8px;

    background-color: %5;
}

QRadioButton::indicator:hover
{
    border: 1px solid %6;
}

QRadioButton::indicator:pressed
{
    background-color: %7;
}

QRadioButton::indicator:checked
{
    border: 5px solid %6;
    border-radius: 8px;

    background-color: %5;
}

QRadioButton::indicator:checked:hover
{
    border: 5px solid %8;
}

QRadioButton::indicator:checked:pressed
{
    border: 5px solid %7;
}

QRadioButton::indicator:disabled
{
    border: %4;
    background-color: %5;
}

)")
            .arg(StyleBuilderUtils::ToCss(palette.textPrimary))
            .arg(palette.spacing.small)
            .arg(StyleBuilderUtils::ToCss(palette.textSecondary))
            .arg(StyleBuilderUtils::Border(1, palette.border))
            .arg(StyleBuilderUtils::ToCss(palette.controlBackground))
            .arg(StyleBuilderUtils::ToCss(palette.accent))
            .arg(StyleBuilderUtils::ToCss(palette.accentPressed))
            .arg(StyleBuilderUtils::ToCss(palette.accentHover));
    }

} // namespace Myelix::UI::Theme
