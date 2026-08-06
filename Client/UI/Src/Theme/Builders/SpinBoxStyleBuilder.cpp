#include "Myelix/UI/Theme/Builders/SpinBoxStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString SpinBoxStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString background = StyleBuilderUtils::ToCss(palette.controlBackground);
        const QString border = StyleBuilderUtils::ToCss(palette.border);
        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);

        const QString accent = StyleBuilderUtils::ToCss(palette.accent);
        const QString hover = StyleBuilderUtils::ToCss(palette.accentHover);
        const QString pressed = StyleBuilderUtils::ToCss(palette.accentPressed);
        const QString disabled = StyleBuilderUtils::ToCss(palette.textSecondary);

        return QString(R"(

QSpinBox,
QDoubleSpinBox
{
    background-color:%1;
    color:%2;

    border:1px solid %3;
    border-radius:4px;

    padding:4px 8px;

    min-height:24px;

    font-family:"%4";
    font-size:%5pt;
}

QSpinBox:hover,
QDoubleSpinBox:hover
{
    border:1px solid %6;
}

QSpinBox:focus,
QDoubleSpinBox:focus
{
    border:1px solid %7;
}

QSpinBox:disabled,
QDoubleSpinBox:disabled
{
    color:%8;
}

QSpinBox::up-button,
QSpinBox::down-button,
QDoubleSpinBox::up-button,
QDoubleSpinBox::down-button
{
    width:18px;

    border:none;

    background:transparent;
}

QSpinBox::up-button:hover,
QSpinBox::down-button:hover,
QDoubleSpinBox::up-button:hover,
QDoubleSpinBox::down-button:hover
{
    background:%6;
}

QSpinBox::up-button:pressed,
QSpinBox::down-button:pressed,
QDoubleSpinBox::up-button:pressed,
QDoubleSpinBox::down-button:pressed
{
    background:%9;
}

QSpinBox::up-arrow,
QSpinBox::down-arrow,
QDoubleSpinBox::up-arrow,
QDoubleSpinBox::down-arrow
{
    image:none;
}

)")
            .arg(background)
            .arg(text)
            .arg(border)
            .arg(QString::fromStdString(palette.typography.family))
            .arg(palette.typography.smallSize)
            .arg(hover)
            .arg(accent)
            .arg(disabled)
            .arg(pressed);
    }

} // namespace Myelix::UI::Theme
