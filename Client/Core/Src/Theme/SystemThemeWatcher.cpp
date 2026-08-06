#include "Myelix/Core/Theme/SystemThemeWatcher.hpp"

#include <QSettings>

namespace Myelix::Core::Theme
{

    SystemThemeWatcher::SystemThemeWatcher() = default;

    SystemThemeWatcher::~SystemThemeWatcher() = default;

    void SystemThemeWatcher::Start()
    {
        CheckTheme();
    }

    void SystemThemeWatcher::Stop() {}

    Theme SystemThemeWatcher::CurrentSystemTheme() const
    {
        QSettings registry(
            "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
            QSettings::NativeFormat);

        const int value = registry.value("AppsUseLightTheme", 0).toInt();

        return value ? Theme::Light : Theme::Dark;
    }

    void SystemThemeWatcher::SetCallback(Callback callback)
    {
        m_callback = std::move(callback);
    }

    void SystemThemeWatcher::CheckTheme()
    {
        if (m_callback)
        {
            m_callback(CurrentSystemTheme());
        }
    }

} // namespace Myelix::Core::Theme
