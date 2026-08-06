#pragma once

#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <QString>

namespace Myelix::UI::Theme
{

    class CheckBoxStyleBuilder final
    {
    public:
        [[nodiscard]]
        static QString Build(const Myelix::Core::Theme::ThemePalette& palette);
    };

} // namespace Myelix::UI::Theme
