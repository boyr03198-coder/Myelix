#pragma once

#include "Myelix/Core/Theme/ThemeManager.hpp"
#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <cstddef>

namespace CoreTheme = Myelix::Core::Theme;

namespace Myelix::UI::Theme
{

    class ThemeEngine final
    {
    public:
        explicit ThemeEngine(CoreTheme::ThemeManager& manager);
        ~ThemeEngine();

        ThemeEngine(const ThemeEngine&) = delete;
        ThemeEngine& operator=(const ThemeEngine&) = delete;

        ThemeEngine(ThemeEngine&&) = delete;
        ThemeEngine& operator=(ThemeEngine&&) = delete;

        void ApplyCurrentTheme();

    private:
        void ApplyTheme(const CoreTheme::ThemePalette& palette);

    private:
        CoreTheme::ThemeManager& m_themeManager;

        std::size_t m_listenerId{0};
    };

} // namespace Myelix::UI::Theme
