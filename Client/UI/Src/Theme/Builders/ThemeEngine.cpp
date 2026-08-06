#include "Myelix/UI/Theme/Builders/ThemeEngine.hpp"

#include "Myelix/UI/Theme/Builders/StyleSheetBuilder.hpp"

#include <QApplication>

namespace CoreTheme = Myelix::Core::Theme;

namespace Myelix::UI::Theme
{

    ThemeEngine::ThemeEngine(CoreTheme::ThemeManager& manager)
        : m_themeManager(manager)
    {
        m_listenerId = m_themeManager.AddListener([this](CoreTheme::Theme)
                                                  { ApplyTheme(m_themeManager.Palette()); });

        ApplyTheme(m_themeManager.Palette());
    }

    ThemeEngine::~ThemeEngine()
    {
        m_themeManager.RemoveListener(m_listenerId);
    }

    void ThemeEngine::ApplyCurrentTheme()
    {
        ApplyTheme(m_themeManager.Palette());
    }

    void ThemeEngine::ApplyTheme(const CoreTheme::ThemePalette& palette)
    {
        if (qApp == nullptr)
        {
            return;
        }

        qApp->setStyleSheet(StyleSheetBuilder::Build(palette));
    }

} // namespace Myelix::UI::Theme
