#include "Myelix/UI/Theme/Builders/CheckBoxStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString CheckBoxStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        return QString(R"(

QCheckBox
{
    color: %1;
    spacing: %2px;
}

QCheckBox:disabled
{
    color: %3;
}

QCheckBox::indicator
{
    width: 16px;
    height: 16px;

    border: 1px solid %4;
    border-radius: 3px;

    background-color: %5;
}

QCheckBox::indicator:hover
{
    border: 1px solid %6;
}

QCheckBox::indicator:checked
{
    background-color: %6;
    border: 1px solid %6;
}

QCheckBox::indicator:checked:hover
{
    background-color: %7;
}

QCheckBox::indicator:pressed
{
    background-color: %8;
}

QCheckBox::indicator:disabled
{
    background-color: %5;
    border: 1px solid %4;
}

)")
            .arg(StyleBuilderUtils::ToCss(palette.textPrimary))
            .arg(palette.spacing.small)
            .arg(StyleBuilderUtils::ToCss(palette.textSecondary))
            .arg(StyleBuilderUtils::ToCss(palette.border))
            .arg(StyleBuilderUtils::ToCss(palette.controlBackground))
            .arg(StyleBuilderUtils::ToCss(palette.accent))
            .arg(StyleBuilderUtils::ToCss(palette.accentHover))
            .arg(StyleBuilderUtils::ToCss(palette.accentPressed));
    }

} // namespace Myelix::UI::Theme
