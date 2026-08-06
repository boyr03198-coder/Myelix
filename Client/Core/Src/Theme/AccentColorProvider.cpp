#include "Myelix/Core/Theme/AccentColorProvider.hpp"

#include <QSettings>

namespace Myelix::Core::Theme
{

    ThemeColor AccentColorProvider::AccentColor() const
    {
        QSettings registry("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\DWM",
                           QSettings::NativeFormat);

        const auto value = registry.value("ColorizationColor");

        if (!value.isValid())
        {
            return DefaultAccent();
        }

        const std::uint32_t argb = value.toUInt();

        ThemeColor color;

        color.red = (argb >> 16) & 0xFF;
        color.green = (argb >> 8) & 0xFF;
        color.blue = argb & 0xFF;

        return color;
    }

    ThemeColor AccentColorProvider::DefaultAccent() const noexcept
    {
        return {0, 120, 215};
    }

} // namespace Myelix::Core::Theme
