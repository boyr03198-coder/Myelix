#pragma once

#include "Myelix/Core/Theme/AccentColorProvider.hpp"
#include "Myelix/Core/Theme/Theme.hpp"
#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <cstddef>
#include <functional>
#include <unordered_map>

namespace Myelix::Core::Theme
{

    class ThemeManager final
    {
    public:
        using ThemeChangedCallback = std::function<void(Theme)>;

        ThemeManager();
        ~ThemeManager() = default;

        ThemeManager(const ThemeManager&) = delete;
        ThemeManager& operator=(const ThemeManager&) = delete;

        ThemeManager(ThemeManager&&) = delete;
        ThemeManager& operator=(ThemeManager&&) = delete;

        [[nodiscard]]
        Theme CurrentTheme() const noexcept;

        [[nodiscard]]
        const ThemePalette& Palette() const noexcept;

        void SetTheme(Theme theme);

        [[nodiscard]]
        std::size_t AddListener(ThemeChangedCallback callback);

        void RemoveListener(std::size_t id);

    private:
        void NotifyListeners();

        void ApplyAccentColor();

    private:
        Theme m_currentTheme{Theme::System};

        ThemePalette m_palette{};

        AccentColorProvider m_accentProvider{};

        std::unordered_map<std::size_t, ThemeChangedCallback> m_listeners;

        std::size_t m_nextListenerId{1};
    };

} // namespace Myelix::Core::Theme
