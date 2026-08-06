#pragma once

#include <string>

namespace Myelix::Core::Theme
{

    struct ThemeTypography
    {
        std::string family;

        int smallSize{};
        int normalSize{};
        int largeSize{};

        int titleSize{};
        int headingSize{};
    };

} // namespace Myelix::Core::Theme
