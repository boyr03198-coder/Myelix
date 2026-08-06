#include "Myelix/UI/Theme/Builders/ProgressBarStyleBuilder.hpp"

#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString ProgressBarStyleBuilder::Build(const Myelix::Core::Theme::ThemePalette& palette)
    {
        const QString background = StyleBuilderUtils::ToCss(palette.controlBackground);
        const QString border = StyleBuilderUtils::ToCss(palette.border);

        const QString accent = StyleBuilderUtils::ToCss(palette.accent);
        const QString accentHover = StyleBuilderUtils::ToCss(palette.accentHover);

        const QString text = StyleBuilderUtils::ToCss(palette.textPrimary);
        const QString disabledText = StyleBuilderUtils::ToCss(palette.textSecondary);

        return QString(R"(

/* ============================================================
   Progress Bar
   ============================================================ */

QProgressBar
{
    background:%1;
    color:%2;

    border:%3;
    border-radius:6px;

    text-align:center;

    min-height:20px;
    max-height:20px;
}

/* Filled portion */

QProgressBar::chunk
{
    background:%4;
    border-radius:5px;
    margin:1px;
}

/* Busy / Indeterminate */

QProgressBar::chunk:indeterminate
{
    background:%5;
}

/* Disabled */

QProgressBar:disabled
{
    color:%6;
    background:%1;
}

QProgressBar::chunk:disabled
{
    background:%6;
}

/* Vertical */

QProgressBar:vertical
{
    min-width:20px;
    max-width:20px;
}

QProgressBar::chunk:vertical
{
    border-radius:5px;
    margin:1px;
}

)")
            .arg(background)
            .arg(text)
            .arg(StyleBuilderUtils::Border(1, palette.border))
            .arg(accent)
            .arg(accentHover)
            .arg(disabledText);
    }

} // namespace Myelix::UI::Theme
