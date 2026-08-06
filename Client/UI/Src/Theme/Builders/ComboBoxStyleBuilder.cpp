#include "Myelix/UI/Theme/Builders/ComboBoxStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString ComboBoxStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString background = StyleBuilderUtils::ToCss(palette.controlBackground);
        const QString border = StyleBuilderUtils::ToCss(palette.border);
        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const QString accent = StyleBuilderUtils::ToCss(palette.accent);
        const QString hover = StyleBuilderUtils::ToCss(palette.accentHover);
        const QString disabled = StyleBuilderUtils::ToCss(palette.textSecondary);

        return QString(R"(

QComboBox
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

QComboBox:hover
{
    border:1px solid %6;
}

QComboBox:focus
{
    border:1px solid %7;
}

QComboBox:disabled
{
    color:%8;
}

QComboBox:editable
{
    background-color:%1;
}

QComboBox::drop-down
{
    width:24px;

    border:none;
    background:transparent;
}

QComboBox::down-arrow
{
    image:none;
}

QComboBox QAbstractItemView
{
    background-color:%1;

    color:%2;

    border:1px solid %3;

    selection-background-color:%7;
    selection-color:%2;

    outline:none;
}

)")
            .arg(background)
            .arg(text)
            .arg(border)
            .arg(QString::fromStdString(palette.typography.family))
            .arg(palette.typography.smallSize)
            .arg(hover)
            .arg(accent)
            .arg(disabled);
    }

} // namespace Myelix::UI::Theme
