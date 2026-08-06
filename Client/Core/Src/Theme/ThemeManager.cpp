#include "Myelix/Core/Theme/ThemeManager.hpp"

#include <algorithm>
#include <cstdint>
#include <utility>

namespace
{

    using namespace Myelix::Core::Theme;

    ThemePalette BuildDarkPalette()
    {
        ThemePalette palette;

        palette.theme = Theme::Dark;

        palette.windowBackground = {30, 30, 30};
        palette.panelBackground = {40, 40, 40};
        palette.controlBackground = {52, 52, 52};

        palette.textPrimary = {240, 240, 240};
        palette.textSecondary = {180, 180, 180};

        palette.border = {70, 70, 70};

        palette.typography = {"Segoe UI", 10, 11, 14, 20, 16};

        palette.spacing = {2, 4, 8, 16, 24};

        return palette;
    }

    ThemePalette BuildLightPalette()
    {
        ThemePalette palette;

        palette.theme = Theme::Light;

        palette.windowBackground = {250, 250, 250};
        palette.panelBackground = {240, 240, 240};
        palette.controlBackground = {255, 255, 255};

        palette.textPrimary = {25, 25, 25};
        palette.textSecondary = {90, 90, 90};

        palette.border = {200, 200, 200};

        palette.typography = {"Segoe UI", 10, 11, 14, 20, 16};

        palette.spacing = {2, 4, 8, 16, 24};

        return palette;
    }

    ThemePalette BuildSystemPalette()
    {
        // Temporary.
        // Later SystemThemeWatcher will choose
        // Light or Dark automatically.

        return BuildDarkPalette();
    }

} // anonymous namespace

namespace Myelix::Core::Theme
{

    ThemeManager::ThemeManager()
    {
        SetTheme(Theme::System);
    }

    Theme ThemeManager::CurrentTheme() const noexcept
    {
        return m_currentTheme;
    }

    const ThemePalette& ThemeManager::Palette() const noexcept
    {
        return m_palette;
    }

    void ThemeManager::SetTheme(Theme theme)
    {
        if (theme == m_currentTheme && m_palette.theme == theme)
        {
            return;
        }

        m_currentTheme = theme;

        switch (theme)
        {
            case Theme::Dark:
                m_palette = BuildDarkPalette();
                break;

            case Theme::Light:
                m_palette = BuildLightPalette();
                break;

            case Theme::System:
                m_palette = BuildSystemPalette();
                break;
        }

        ApplyAccentColor();

        NotifyListeners();
    }

    std::size_t ThemeManager::AddListener(ThemeChangedCallback callback)
    {
        const auto id = m_nextListenerId++;

        m_listeners.emplace(id, std::move(callback));

        return id;
    }

    void ThemeManager::RemoveListener(std::size_t id)
    {
        m_listeners.erase(id);
    }

    void ThemeManager::NotifyListeners()
    {
        for (auto& [id, callback] : m_listeners)
        {
            if (callback)
            {
                callback(m_currentTheme);
            }
        }
    }

    void ThemeManager::ApplyAccentColor()
    {
        m_palette.accent = m_accentProvider.AccentColor();
        m_palette.accentHover = m_palette.accent.Lighter(20);
        m_palette.accentPressed = m_palette.accent.Darker(20);
    }

} // namespace Myelix::Core::Theme
