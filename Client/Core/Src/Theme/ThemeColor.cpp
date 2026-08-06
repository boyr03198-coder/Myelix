#include "Myelix/Core/Theme/ThemeColor.hpp"

#include <algorithm>

namespace Myelix::Core::Theme
{

    ThemeColor ThemeColor::Lighter(int amount) const noexcept
    {
        return {static_cast<std::uint8_t>(std::clamp(static_cast<int>(red) + amount, 0, 255)),
                static_cast<std::uint8_t>(std::clamp(static_cast<int>(green) + amount, 0, 255)),
                static_cast<std::uint8_t>(std::clamp(static_cast<int>(blue) + amount, 0, 255))};
    }

    ThemeColor ThemeColor::Darker(int amount) const noexcept
    {
        return {static_cast<std::uint8_t>(std::clamp(static_cast<int>(red) - amount, 0, 255)),
                static_cast<std::uint8_t>(std::clamp(static_cast<int>(green) - amount, 0, 255)),
                static_cast<std::uint8_t>(std::clamp(static_cast<int>(blue) - amount, 0, 255))};
    }

} // namespace Myelix::Core::Theme
