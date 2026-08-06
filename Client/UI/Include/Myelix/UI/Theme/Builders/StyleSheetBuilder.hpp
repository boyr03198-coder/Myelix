#pragma once

#include "Myelix/Core/Theme/ThemePalette.hpp"

#include <QString>

namespace Myelix::UI::Theme
{

    class StyleSheetBuilder final
    {
    public:
        [[nodiscard]]
        static QString Build(const Myelix::Core::Theme::ThemePalette& palette);

    private:
        [[nodiscard]]
        static QString BuildWidgets(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildButtons(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildInputs(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildCheckBoxes(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildRadioButtons(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildMenus(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildViews(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildScrollBars(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildToolTips(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildComboBoxes(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildSpinBoxes(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildSliders(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildGroupBoxes(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildTabs(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildDockWidgets(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildToolBars(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildProgressBars(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildPropertyGrids(const Myelix::Core::Theme::ThemePalette& palette);

        [[nodiscard]]
        static QString BuildRibbon(const Myelix::Core::Theme::ThemePalette& palette);
    };

} // namespace Myelix::UI::Theme
