#include "Myelix/UI/Theme/Builders/RibbonStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString RibbonStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const auto window = StyleBuilderUtils::ToCss(palette.windowBackground);
        const auto panel = StyleBuilderUtils::ToCss(palette.panelBackground);
        const auto control = StyleBuilderUtils::ToCss(palette.controlBackground);

        const auto text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const auto secondary = StyleBuilderUtils::ToCss(palette.textSecondary);

        const auto border = StyleBuilderUtils::ToCss(palette.border);

        const auto accent = StyleBuilderUtils::ToCss(palette.accent);
        const auto hover = StyleBuilderUtils::ToCss(palette.accentHover);
        const auto pressed = StyleBuilderUtils::ToCss(palette.accentPressed);

        return QString(R"(

/* ============================================================
   Ribbon Bar
   ============================================================ */

QWidget#RibbonBar
{
    background:%1;
    border-bottom:1px solid %2;
}

/* ============================================================
   Ribbon Pages
   ============================================================ */

QWidget#RibbonPage
{
    background:%3;
}

/* ============================================================
   Ribbon Groups
   ============================================================ */

QGroupBox#RibbonGroup
{
    background:%3;

    border:1px solid %2;

    margin-top:12px;

    padding:6px;

    border-radius:4px;
}

QGroupBox#RibbonGroup::title
{
    color:%4;

    subcontrol-origin:margin;

    left:8px;
}

/* ============================================================
   Ribbon Tabs
   ============================================================ */

QTabBar#RibbonTabBar::tab
{
    background:%1;

    color:%4;

    padding:8px 18px;

    border:1px solid transparent;
}

QTabBar#RibbonTabBar::tab:selected
{
    background:%5;

    color:white;
}

QTabBar#RibbonTabBar::tab:hover
{
    background:%6;
}

/* ============================================================
   Quick Access Toolbar
   ============================================================ */

QToolBar#QuickAccessToolBar
{
    background:%1;

    border:none;

    spacing:2px;
}

QToolButton#QuickAccessButton
{
    background:transparent;

    color:%4;

    padding:5px;

    border-radius:3px;
}

QToolButton#QuickAccessButton:hover
{
    background:%6;
}

QToolButton#QuickAccessButton:pressed
{
    background:%7;
}

/* ============================================================
   Application Button
   ============================================================ */

QPushButton#ApplicationButton
{
    background:%5;

    color:white;

    border:none;

    border-radius:5px;

    padding:8px 18px;

    font-weight:bold;
}

QPushButton#ApplicationButton:hover
{
    background:%6;
}

QPushButton#ApplicationButton:pressed
{
    background:%7;
}

/* ============================================================
   Backstage View
   ============================================================ */

QWidget#BackstageView
{
    background:%3;
}

QListView#BackstageMenu
{
    background:%1;

    color:%4;

    border:none;
}

QListView#BackstageMenu::item
{
    padding:10px;
}

QListView#BackstageMenu::item:selected
{
    background:%5;

    color:white;
}

QListView#BackstageMenu::item:hover
{
    background:%6;
}

/* ============================================================
   Ribbon Gallery
   ============================================================ */

QListView#RibbonGallery
{
    background:%3;

    border:1px solid %2;
}

QListView#RibbonGallery::item
{
    padding:4px;
}

QListView#RibbonGallery::item:hover
{
    background:%6;
}

QListView#RibbonGallery::item:selected
{
    background:%5;

    color:white;
}

/* ============================================================
   Contextual Tabs
   ============================================================ */

QTabBar#ContextRibbonTabs::tab
{
    background:%5;

    color:white;

    padding:8px 18px;
}

QTabBar#ContextRibbonTabs::tab:selected
{
    background:%7;
}

QTabBar#ContextRibbonTabs::tab:hover
{
    background:%6;
}

)")
            .arg(window)
            .arg(border)
            .arg(panel)
            .arg(text)
            .arg(accent)
            .arg(hover)
            .arg(pressed);
    }

} // namespace Myelix::UI::Theme
