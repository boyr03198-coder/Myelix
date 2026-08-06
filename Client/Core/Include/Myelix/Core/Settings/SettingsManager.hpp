#pragma once

#include "Myelix/Core/Theme/Theme.hpp"

#include <QSettings>

namespace Myelix::Core::Settings
{

    class SettingsManager final
    {
    public:
        SettingsManager();
        ~SettingsManager() = default;

        SettingsManager(const SettingsManager&) = delete;
        SettingsManager& operator=(const SettingsManager&) = delete;

        SettingsManager(SettingsManager&&) = delete;
        SettingsManager& operator=(SettingsManager&&) = delete;

        void Load();
        void Save();

        [[nodiscard]]
        Theme::Theme CurrentTheme() const noexcept;

        void SetTheme(Theme::Theme theme);

    private:
        Theme::Theme m_theme{Theme::Theme::System};

        QSettings m_settings;
    };

} // namespace Myelix::Core::Settings
