#include "Myelix/Core/Settings/SettingsManager.hpp"

#include "Myelix/Core/Settings/SettingsKeys.hpp"

namespace Myelix::Core::Settings
{

    SettingsManager::SettingsManager()
        : m_settings("WeCanDo", "Myelix")
    {
    }

    void SettingsManager::Load()
    {
        const int value =
            m_settings.value(Keys::Theme, static_cast<int>(Theme::Theme::System)).toInt();

        m_theme = static_cast<Theme::Theme>(value);
    }

    void SettingsManager::Save()
    {
        m_settings.setValue(Keys::Theme, static_cast<int>(m_theme));

        m_settings.sync();
    }

    Theme::Theme SettingsManager::CurrentTheme() const noexcept
    {
        return m_theme;
    }

    void SettingsManager::SetTheme(Theme::Theme theme)
    {
        m_theme = theme;
    }

} // namespace Myelix::Core::Settings
