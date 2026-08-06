#pragma once

#include "Myelix/Core/Theme/Theme.hpp"
#include "Myelix/Core/Theme/ThemeColor.hpp"
#include "Myelix/Core/Theme/ThemeSpacing.hpp"
#include "Myelix/Core/Theme/ThemeTypography.hpp"

namespace Myelix::Core::Theme
{

    struct ThemePalette
    {
        //======================================================================
        // Theme Identity
        //======================================================================

        Theme theme{Theme::System};

        //======================================================================
        // Window & Surface Colors
        //======================================================================

        ThemeColor windowBackground;
        ThemeColor dialogBackground;

        ThemeColor panelBackground;
        ThemeColor toolbarBackground;
        ThemeColor statusBarBackground;

        ThemeColor surface;
        ThemeColor surfaceRaised;
        ThemeColor surfaceSunken;

        ThemeColor controlBackground;
        ThemeColor popupBackground;

        //======================================================================
        // Text Colors
        //======================================================================

        ThemeColor textPrimary;
        ThemeColor textSecondary;
        ThemeColor textDisabled;
        ThemeColor textPlaceholder;
        ThemeColor textInverse;

        //======================================================================
        // Accent Colors
        //======================================================================

        ThemeColor accent;
        ThemeColor accentHover;
        ThemeColor accentPressed;
        ThemeColor accentDisabled;

        //======================================================================
        // Borders
        //======================================================================

        ThemeColor border;
        ThemeColor borderLight;
        ThemeColor borderDark;
        ThemeColor focusBorder;

        //======================================================================
        // Selection
        //======================================================================

        ThemeColor selectionBackground;
        ThemeColor selectionText;
        ThemeColor hoverBackground;
        ThemeColor highlight;

        //======================================================================
        // State Colors
        //======================================================================

        ThemeColor success;
        ThemeColor warning;
        ThemeColor error;
        ThemeColor information;

        //======================================================================
        // Hyperlinks
        //======================================================================

        ThemeColor hyperlink;
        ThemeColor hyperlinkVisited;

        //======================================================================
        // Buttons
        //======================================================================

        ThemeColor buttonBackground;
        ThemeColor buttonHover;
        ThemeColor buttonPressed;
        ThemeColor buttonDisabled;

        ThemeColor buttonText;
        ThemeColor buttonTextDisabled;

        //======================================================================
        // Input Controls
        //======================================================================

        ThemeColor inputBackground;
        ThemeColor inputBorder;
        ThemeColor inputText;
        ThemeColor inputPlaceholder;

        //======================================================================
        // Disabled Controls
        //======================================================================

        ThemeColor disabledBackground;
        ThemeColor disabledForeground;

        //======================================================================
        // Menus
        //======================================================================

        ThemeColor menuBackground;
        ThemeColor menuHover;
        ThemeColor menuSeparator;

        //======================================================================
        // Scroll Bars
        //======================================================================

        ThemeColor scrollBarBackground;
        ThemeColor scrollBarHandle;
        ThemeColor scrollBarHandleHover;

        //======================================================================
        // Tree / List / Table
        //======================================================================

        ThemeColor headerBackground;
        ThemeColor headerText;

        ThemeColor alternateRowBackground;
        ThemeColor gridLine;

        //======================================================================
        // Tabs
        //======================================================================

        ThemeColor tabBackground;
        ThemeColor tabActive;
        ThemeColor tabHover;
        ThemeColor tabText;

        //======================================================================
        // Progress
        //======================================================================

        ThemeColor progressBackground;
        ThemeColor progressChunk;

        //======================================================================
        // Tooltips
        //======================================================================

        ThemeColor tooltipBackground;
        ThemeColor tooltipText;

        //======================================================================
        // Shadows
        //======================================================================

        ThemeColor shadow;

        //======================================================================
        // Typography
        //======================================================================

        ThemeTypography typography;

        //======================================================================
        // Layout
        //======================================================================

        ThemeSpacing spacing;
    };

} // namespace Myelix::Core::Theme
