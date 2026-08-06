#include "Myelix/UI/Theme/Builders/StyleSheetBuilder.hpp"

#include "Myelix/UI/Theme/Builders/ButtonStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/CheckBoxStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/ComboBoxStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/DockWidgetStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/GroupBoxStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/InputStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/MenuStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/ProgressBarStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/RadioButtonStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/ScrollBarStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/SliderStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/SpinBoxStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/TabStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/ToolBarStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/ToolTipStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/ViewStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/WidgetStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/PropertyGridStyleBuilder.hpp"
#include "Myelix/UI/Theme/Builders/RibbonStyleBuilder.hpp"


namespace CoreTheme = Myelix::Core::Theme;

namespace Myelix::UI::Theme
{

    QString StyleSheetBuilder::Build(const CoreTheme::ThemePalette& palette)
    {
        QString style;

        style += BuildWidgets(palette);
        style += BuildButtons(palette);
        style += BuildInputs(palette);

        style += BuildCheckBoxes(palette);
        style += BuildRadioButtons(palette);

        style += BuildMenus(palette);
        style += BuildViews(palette);
        style += BuildScrollBars(palette);
        style += BuildToolTips(palette);

        style += BuildComboBoxes(palette);
        style += BuildSpinBoxes(palette);
        style += BuildSliders(palette);
        style += BuildGroupBoxes(palette);

        style += BuildTabs(palette);
        style += BuildDockWidgets(palette);
        style += BuildToolBars(palette);
        style += BuildProgressBars(palette);

        style += BuildPropertyGrids(palette);
        style += BuildRibbon(palette);

        return style;
    }

    QString StyleSheetBuilder::BuildWidgets(const CoreTheme::ThemePalette& palette)
    {
        return WidgetStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildButtons(const CoreTheme::ThemePalette& palette)
    {
        return ButtonStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildInputs(const CoreTheme::ThemePalette& palette)
    {
        return InputStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildMenus(const CoreTheme::ThemePalette& palette)
    {
        return MenuStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildViews(const CoreTheme::ThemePalette& palette)
    {
        return ViewStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildScrollBars(const CoreTheme::ThemePalette& palette)
    {
        return ScrollBarStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildToolTips(const CoreTheme::ThemePalette& palette)
    {
        return ToolTipStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildCheckBoxes(const CoreTheme::ThemePalette& palette)
    {
        return CheckBoxStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildRadioButtons(const CoreTheme::ThemePalette& palette)
    {
        return RadioButtonStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildComboBoxes(const CoreTheme::ThemePalette& palette)
    {
        return ComboBoxStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildSpinBoxes(const CoreTheme::ThemePalette& palette)
    {
        return SpinBoxStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildSliders(const CoreTheme::ThemePalette& palette)
    {
        return SliderStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildGroupBoxes(const CoreTheme::ThemePalette& palette)
    {
        return GroupBoxStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildTabs(const CoreTheme::ThemePalette& palette)
    {
        return TabStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildDockWidgets(const CoreTheme::ThemePalette& palette)
    {
        return DockWidgetStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildToolBars(const CoreTheme::ThemePalette& palette)
    {
        return ToolBarStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildProgressBars(const CoreTheme::ThemePalette& palette)
    {
        return ProgressBarStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildPropertyGrids(const CoreTheme::ThemePalette& palette)
    {
        return PropertyGridStyleBuilder::Build(palette);
    }

    QString StyleSheetBuilder::BuildRibbon(const CoreTheme::ThemePalette& palette)
    {
        return RibbonStyleBuilder::Build(palette);
    }

} // namespace Myelix::UI::Theme
