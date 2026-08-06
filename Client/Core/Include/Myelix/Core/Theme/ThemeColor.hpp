#pragma once

#include <cstdint>

namespace Myelix::Core::Theme
{

    struct ThemeColor
    {
        std::uint8_t red{};
        std::uint8_t green{};
        std::uint8_t blue{};

        [[nodiscard]]
        ThemeColor Lighter(int amount) const noexcept;

        [[nodiscard]]
        ThemeColor Darker(int amount) const noexcept;
    };

} // namespace Myelix::Core::Theme
