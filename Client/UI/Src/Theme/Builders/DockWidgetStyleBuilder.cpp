#include "Myelix/UI/Theme/Builders/DockWidgetStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString DockWidgetStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
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
  QDockWidget
==================================================*/

QDockWidget
{
    background:%1;

    border:1px solid %2;
}

/*==================================================
  Title Bar
==================================================*/

QDockWidget::title
{
    background:%3;

    color:%4;

    text-align:left;

    padding-left:8px;
    padding-right:8px;

    height:28px;

    border-bottom:1px solid %2;

    font-family:"%5";
    font-size:%6pt;
    font-weight:600;
}

/*==================================================
  Close Button
==================================================*/

QDockWidget::close-button
{
    background:transparent;

    border:none;

    width:18px;
    height:18px;
}

QDockWidget::close-button:hover
{
    background:%8;

    border-radius:3px;
}

QDockWidget::close-button:pressed
{
    background:%7;
}

/*==================================================
  Float Button
==================================================*/

QDockWidget::float-button
{
    background:transparent;

    border:none;

    width:18px;
    height:18px;
}

QDockWidget::float-button:hover
{
    background:%8;

    border-radius:3px;
}

QDockWidget::float-button:pressed
{
    background:%7;
}

/*==================================================
  Dock Separators
==================================================*/

QMainWindow::separator
{
    background:%2;

    width:4px;
    height:4px;
}

QMainWindow::separator:hover
{
    background:%7;
}

/*==================================================
  Disabled
==================================================*/

QDockWidget:disabled
{
    color:%9;
}

)")
            .arg(panel)
            .arg(border)
            .arg(control)
            .arg(text)
            .arg(QString::fromStdString(palette.typography.family))
            .arg(palette.typography.normalSize)
            .arg(accent)
            .arg(hover)
            .arg(disabled);
    }

} // namespace Myelix::UI::Theme
