#include "Myelix/UI/Theme/Builders/StyleBuilderUtils.hpp"

namespace Myelix::UI::Theme
{

    QString StyleBuilderUtils::ToCss(const Myelix::Core::Theme::ThemeColor& color)
    {
        return QString("#%1%2%3")
            .arg(color.red, 2, 16, QChar('0'))
            .arg(color.green, 2, 16, QChar('0'))
            .arg(color.blue, 2, 16, QChar('0'))
            .toUpper();
    }

    QString StyleBuilderUtils::Px(int value)
    {
        return QString("%1px").arg(value);
    }

    QString StyleBuilderUtils::Border(int width, const Myelix::Core::Theme::ThemeColor& color)
    {
        return QString("%1px solid %2").arg(width).arg(ToCss(color));
    }

    QString StyleBuilderUtils::Radius(int radius)
    {
        return QString("%1px").arg(radius);
    }

} // namespace Myelix::UI::Theme
