#include "Myelix/UI/Theme/Builders/PropertyGridStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString PropertyGridStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const auto background = StyleBuilderUtils::ToCss(palette.controlBackground);
        const auto panel = StyleBuilderUtils::ToCss(palette.panelBackground);
        const auto border = StyleBuilderUtils::ToCss(palette.border);

        const auto text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const auto secondary = StyleBuilderUtils::ToCss(palette.textSecondary);

        const auto accent = StyleBuilderUtils::ToCss(palette.accent);
        const auto hover = StyleBuilderUtils::ToCss(palette.accentHover);

        return QString(R"(

/* ============================================================
   Property Grid
   ============================================================ */

QtTreePropertyBrowser,
QTreeView[propertyGrid="true"]
{
    background:%1;
    alternate-background-color:%2;
    color:%3;

    border:1px solid %4;

    selection-background-color:%5;
    selection-color:%3;

    gridline-color:%4;

    outline:none;
}

/* Category rows */

QtTreePropertyBrowser::branch,
QTreeView[propertyGrid="true"]::branch
{
    background:%2;
}

/* Property rows */

QtTreePropertyBrowser::item,
QTreeView[propertyGrid="true"]::item
{
    padding:4px;
    border:none;
}

QtTreePropertyBrowser::item:hover,
QTreeView[propertyGrid="true"]::item:hover
{
    background:%6;
}

QtTreePropertyBrowser::item:selected,
QTreeView[propertyGrid="true"]::item:selected
{
    background:%5;
    color:%3;
}

/* Editors */

QtTreePropertyBrowser QLineEdit,
QtTreePropertyBrowser QSpinBox,
QtTreePropertyBrowser QDoubleSpinBox,
QtTreePropertyBrowser QComboBox
{
    border:1px solid %4;
    background:%1;
    color:%3;
    padding:3px;
}

/* Expand / Collapse */

QtTreePropertyBrowser::branch:closed:has-children,
QTreeView[propertyGrid="true"]::branch:closed:has-children
{
    image:none;
}

QtTreePropertyBrowser::branch:open:has-children,
QTreeView[propertyGrid="true"]::branch:open:has-children
{
    image:none;
}

/* Alternating rows */

QtTreePropertyBrowser::item:alternate,
QTreeView[propertyGrid="true"]::item:alternate
{
    background:%2;
}

/* Disabled */

QtTreePropertyBrowser:disabled,
QTreeView[propertyGrid="true"]:disabled
{
    color:%7;
}

)")
            .arg(background)
            .arg(panel)
            .arg(text)
            .arg(border)
            .arg(accent)
            .arg(hover)
            .arg(secondary);
    }

} // namespace Myelix::UI::Theme
