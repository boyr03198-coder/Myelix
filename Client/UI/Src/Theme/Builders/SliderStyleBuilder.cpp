#include "Myelix/UI/Theme/Builders/SliderStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString SliderStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString groove = StyleBuilderUtils::ToCss(palette.border);
        const QString handle = StyleBuilderUtils::ToCss(palette.accent);
        const QString hover = StyleBuilderUtils::ToCss(palette.accentHover);
        const QString pressed = StyleBuilderUtils::ToCss(palette.accentPressed);
        const QString background = StyleBuilderUtils::ToCss(palette.controlBackground);

        return QString(R"(

/* -------------------------------------------------
 * QSlider
 * ------------------------------------------------- */

QSlider::groove:horizontal
{
    background:%1;
    height:6px;

    border-radius:3px;
}

QSlider::sub-page:horizontal
{
    background:%2;

    border-radius:3px;
}

QSlider::add-page:horizontal
{
    background:%5;

    border-radius:3px;
}

QSlider::handle:horizontal
{
    background:%2;

    width:16px;

    margin:-5px 0;

    border-radius:8px;
}

QSlider::handle:horizontal:hover
{
    background:%3;
}

QSlider::handle:horizontal:pressed
{
    background:%4;
}

/* ------------------------------------------- */

QSlider::groove:vertical
{
    background:%1;

    width:6px;

    border-radius:3px;
}

QSlider::sub-page:vertical
{
    background:%2;

    border-radius:3px;
}

QSlider::add-page:vertical
{
    background:%5;

    border-radius:3px;
}

QSlider::handle:vertical
{
    background:%2;

    height:16px;

    margin:0 -5px;

    border-radius:8px;
}

QSlider::handle:vertical:hover
{
    background:%3;
}

QSlider::handle:vertical:pressed
{
    background:%4;
}

)")
            .arg(groove)
            .arg(handle)
            .arg(hover)
            .arg(pressed)
            .arg(background);
    }

} // namespace Myelix::UI::Theme
