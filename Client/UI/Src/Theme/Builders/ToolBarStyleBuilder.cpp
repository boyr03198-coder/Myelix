#include "Myelix/UI/Theme/Builders/ToolBarStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString ToolBarStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString panel = StyleBuilderUtils::ToCss(palette.panelBackground);
        const QString control = StyleBuilderUtils::ToCss(palette.controlBackground);
        const QString border = StyleBuilderUtils::ToCss(palette.border);

        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const QString disabled = StyleBuilderUtils::ToCss(palette.textSecondary);

        const QString accent = StyleBuilderUtils::ToCss(palette.accent);
        const QString hover = StyleBuilderUtils::ToCss(palette.accentHover);
        const QString pressed = StyleBuilderUtils::ToCss(palette.accentPressed);

        return QString(R"(

/*==================================================
  QToolBar
==================================================*/

QToolBar
{
    background:%1;

    border:none;

    spacing:4px;

    padding:4px;
}

/*==================================================
  Toolbar Buttons
==================================================*/

QToolBar QToolButton
{
    background:transparent;

    color:%4;

    border:1px solid transparent;

    border-radius:4px;

    padding:4px 8px;

    min-width:28px;
    min-height:28px;
}

QToolBar QToolButton:hover
{
    background:%7;

    border:1px solid %2;
}

QToolBar QToolButton:pressed
{
    background:%8;
}

QToolBar QToolButton:checked
{
    background:%6;

    border:1px solid %6;

    color:white;
}

QToolBar QToolButton:disabled
{
    color:%5;
}

/*==================================================
  Separators
==================================================*/

QToolBar::separator
{
    background:%2;

    width:1px;
    height:20px;

    margin:4px;
}

/*==================================================
  Extension Button
==================================================*/

QToolBar QToolButton#qt_toolbar_ext_button
{
    background:%3;

    border:1px solid %2;

    border-radius:4px;
}

QToolBar QToolButton#qt_toolbar_ext_button:hover
{
    background:%7;
}

/*==================================================
  Movable Handle
==================================================*/

QToolBar::handle
{
    background:%2;

    width:6px;
}

)")
            .arg(panel)
            .arg(border)
            .arg(control)
            .arg(text)
            .arg(disabled)
            .arg(accent)
            .arg(hover)
            .arg(pressed);
    }

} // namespace Myelix::UI::Theme
