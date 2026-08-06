#pragma once

#include "Myelix/Core/Theme/ThemeColor.hpp"

namespace Myelix::Core::Theme
{

    class AccentColorProvider final
    {
    public:
        AccentColorProvider() = default;
        ~AccentColorProvider() = default;

        [[nodiscard]]
        ThemeColor AccentColor() const;

    private:
        [[nodiscard]]
        ThemeColor DefaultAccent() const noexcept;
    };

} // namespace Myelix::Core::Theme
