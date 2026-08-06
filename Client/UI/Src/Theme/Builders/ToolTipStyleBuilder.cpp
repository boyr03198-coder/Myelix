#include "Myelix/UI/Theme/Builders/ToolTipStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString ToolTipStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString background = StyleBuilderUtils::ToCss(palette.controlBackground);
        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const QString border = StyleBuilderUtils::ToCss(palette.border);

        return QString(R"(

QToolTip
{
    background-color:%1;
    color:%2;

    border:1px solid %3;
    border-radius:4px;

    padding:%4px;

    font-family:"%5";
    font-size:%6pt;
}

)")
            .arg(background)
            .arg(text)
            .arg(border)
            .arg(palette.spacing.small)
            .arg(QString::fromStdString(palette.typography.family))
            .arg(palette.typography.smallSize);
    }

} // namespace Myelix::UI::Theme
