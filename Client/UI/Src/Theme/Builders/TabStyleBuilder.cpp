#include "Myelix/UI/Theme/Builders/TabStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString TabStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString panel = StyleBuilderUtils::ToCss(palette.panelBackground);
        const QString control = StyleBuilderUtils::ToCss(palette.controlBackground);
        const QString border = StyleBuilderUtils::ToCss(palette.border);

        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const QString disabled = StyleBuilderUtils::ToCss(palette.textSecondary);

        const QString accent = StyleBuilderUtils::ToCss(palette.accent);
        const QString hover = StyleBuilderUtils::ToCss(palette.accentHover);

        return QString(R"(

/*==================================================
  QTabWidget
==================================================*/

QTabWidget::pane
{
    background:%1;

    border:1px solid %2;

    border-radius:4px;
}

/*==================================================
  QTabBar
==================================================*/

QTabBar::tab
{
    background:%3;

    color:%4;

    border:1px solid %2;

    padding:6px 12px;

    min-width:90px;
    min-height:24px;

    margin-right:2px;
}

QTabBar::tab:selected
{
    background:%6;

    color:%4;
}

QTabBar::tab:hover:!selected
{
    background:%7;
}

QTabBar::tab:disabled
{
    color:%5;
}

/*==================================================
  Close Button
==================================================*/

QTabBar::close-button
{
    image:none;

    width:14px;
    height:14px;
}

QTabBar::close-button:hover
{
    background:%7;

    border-radius:7px;
}

/*==================================================
  Scroll Buttons
==================================================*/

QTabBar QToolButton
{
    background:%3;

    border:1px solid %2;

    padding:2px;
}

QTabBar QToolButton:hover
{
    background:%7;
}

/*==================================================
  Document Mode
==================================================*/

QTabWidget::pane:top
{
    border-top:1px solid %2;
}

QTabWidget::pane:bottom
{
    border-bottom:1px solid %2;
}

QTabWidget::pane:left
{
    border-left:1px solid %2;
}

QTabWidget::pane:right
{
    border-right:1px solid %2;
}

/*==================================================
  North
==================================================*/

QTabBar::tab:top
{
    border-top-left-radius:4px;
    border-top-right-radius:4px;
}

/*==================================================
  South
==================================================*/

QTabBar::tab:bottom
{
    border-bottom-left-radius:4px;
    border-bottom-right-radius:4px;
}

/*==================================================
  East
==================================================*/

QTabBar::tab:right
{
    border-top-right-radius:4px;
    border-bottom-right-radius:4px;
}

/*==================================================
  West
==================================================*/

QTabBar::tab:left
{
    border-top-left-radius:4px;
    border-bottom-left-radius:4px;
}

)")
            .arg(panel)
            .arg(border)
            .arg(control)
            .arg(text)
            .arg(disabled)
            .arg(accent)
            .arg(hover);
    }

} // namespace Myelix::UI::Theme
