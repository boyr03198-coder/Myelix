#pragma once

#include "Myelix/Core/Theme/Theme.hpp"

#include <functional>

namespace Myelix::Core::Theme
{

    class SystemThemeWatcher final
    {
    public:
        using Callback = std::function<void(Theme)>;

        SystemThemeWatcher();
        ~SystemThemeWatcher();

        SystemThemeWatcher(const SystemThemeWatcher&) = delete;
        SystemThemeWatcher& operator=(const SystemThemeWatcher&) = delete;

        void Start();
        void Stop();

        [[nodiscard]]
        Theme CurrentSystemTheme() const;

        void SetCallback(Callback callback);

    private:
        void CheckTheme();

    private:
        Callback m_callback;
    };

} // namespace Myelix::Core::Theme
