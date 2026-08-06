#include "Myelix/UI/Theme/Builders/GroupBoxStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString GroupBoxStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString border = StyleBuilderUtils::ToCss(palette.border);
        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const QString panel = StyleBuilderUtils::ToCss(palette.panelBackground);

        return QString(R"(

/*--------------------------------------------------
  QGroupBox
--------------------------------------------------*/

QGroupBox
{
    background-color:%1;

    color:%2;

    border:1px solid %3;
    border-radius:6px;

    margin-top:10px;

    padding-top:10px;
    padding-left:8px;
    padding-right:8px;
    padding-bottom:8px;

    font-family:"%4";
    font-size:%5pt;
    font-weight:600;
}

QGroupBox::title
{
    subcontrol-origin:margin;
    subcontrol-position:top left;

    left:10px;

    padding:0 6px;

    background-color:%1;

    color:%2;
}

)")
            .arg(panel)
            .arg(text)
            .arg(border)
            .arg(QString::fromStdString(palette.typography.family))
            .arg(palette.typography.normalSize);
    }

} // namespace Myelix::UI::Theme
