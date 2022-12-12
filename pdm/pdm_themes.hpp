//
// Created by Mike Yang on 11/20/2022.
//

#include "imgui.h"
#define SPECTRUM_USE_LIGHT_THEME

namespace PDM {
  namespace THEME{
    const float CHECKBOX_BORDER_SIZE = 2.0f;
    const float CHECKBOX_ROUNDING = 2.0f;
  }
  void pdm_style_flat_dark() {
    // Material Flat style by ImJC1C from ImThemes
    ImGuiStyle &style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.5f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 0.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 0.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Left;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(0.8313725590705872f, 0.8470588326454163f, 0.8784313797950745f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.8313725590705872f, 0.8470588326454163f, 0.8784313797950745f,
                                                 0.501960813999176f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1725490242242813f, 0.1921568661928177f, 0.2352941185235977f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.1587982773780823f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.1725490242242813f, 0.1921568661928177f, 0.2352941185235977f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f,
                                            0.501960813999176f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f,
                                                   0.250980406999588f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f,
                                                     1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.5333333611488342f, 0.5333333611488342f, 0.5333333611488342f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.3333333432674408f, 0.3333333432674408f, 0.3333333432674408f,
                                                         1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.6000000238418579f, 0.6000000238418579f, 0.6000000238418579f,
                                                        1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.239215686917305f, 0.5215686559677124f, 0.8784313797950745f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9803921580314636f,
                                                     1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f,
                                           0.501960813999176f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f,
                                                  0.250980406999588f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f,
                                                     0.7799999713897705f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f,
                                                    1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f,
                                                      0.250980406999588f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f,
                                                     1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f,
                                               0.250980406999588f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f,
                                                       1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f,
                                                      1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f,
                                                     0.5021458864212036f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.03862661123275757f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f,
                                                          0.7529411911964417f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f,
                                                      0.7529411911964417f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f,
                                                     0.7529411911964417f);
  }

  namespace Spectrum {
    // a list of changes introduced to change the look of the widgets.
    // Collected here as const rather than being magic numbers spread
    // around imgui.cpp and imgui_widgets.cpp.
    const float CHECKBOX_BORDER_SIZE = 2.0f;
    const float CHECKBOX_ROUNDING = 2.0f;

    // Load SourceSansProRegular and sets it as a default font.
    // You may want to call ImGui::GetIO().Fonts->Clear() before this
    void LoadFont(float size = 16.0f);

    // Sets the ImGui style to Spectrum
    void StyleColorsSpectrum();

    namespace { // Unnamed namespace, since we only use this here.
      unsigned int Color(unsigned int c) {
        // add alpha.
        // also swap red and blue channel for some reason.
        // todo: figure out why, and fix it.
        const short a = 0xFF;
        const short r = (c >> 16) & 0xFF;
        const short g = (c >> 8) & 0xFF;
        const short b = (c >> 0) & 0xFF;
        return (a << 24)
               | (r << 0)
               | (g << 8)
               | (b << 16);
      }
    }
    // all colors are from http://spectrum.corp.adobe.com/color.html

    inline unsigned int color_alpha(unsigned int alpha, unsigned int c) {
      return ((alpha & 0xFF) << 24) | (c & 0x00FFFFFF);
    }

    namespace Static { // static colors
      const unsigned int NONE = 0x00000000; // transparent
      const unsigned int WHITE = Color(0xFFFFFF);
      const unsigned int BLACK = Color(0x000000);
      const unsigned int GRAY200 = Color(0xF4F4F4);
      const unsigned int GRAY300 = Color(0xEAEAEA);
      const unsigned int GRAY400 = Color(0xD3D3D3);
      const unsigned int GRAY500 = Color(0xBCBCBC);
      const unsigned int GRAY600 = Color(0x959595);
      const unsigned int GRAY700 = Color(0x767676);
      const unsigned int GRAY800 = Color(0x505050);
      const unsigned int GRAY900 = Color(0x323232);
      const unsigned int BLUE400 = Color(0x378EF0);
      const unsigned int BLUE500 = Color(0x2680EB);
      const unsigned int BLUE600 = Color(0x1473E6);
      const unsigned int BLUE700 = Color(0x0D66D0);
      const unsigned int RED400 = Color(0xEC5B62);
      const unsigned int RED500 = Color(0xE34850);
      const unsigned int RED600 = Color(0xD7373F);
      const unsigned int RED700 = Color(0xC9252D);
      const unsigned int ORANGE400 = Color(0xF29423);
      const unsigned int ORANGE500 = Color(0xE68619);
      const unsigned int ORANGE600 = Color(0xDA7B11);
      const unsigned int ORANGE700 = Color(0xCB6F10);
      const unsigned int GREEN400 = Color(0x33AB84);
      const unsigned int GREEN500 = Color(0x2D9D78);
      const unsigned int GREEN600 = Color(0x268E6C);
      const unsigned int GREEN700 = Color(0x12805C);
    }
    namespace Light  {
    const unsigned int GRAY50 = Color(0xFFFFFF);
    const unsigned int GRAY75 = Color(0xFAFAFA);
    const unsigned int GRAY100 = Color(0xF5F5F5);
    const unsigned int GRAY200 = Color(0xEAEAEA);
    const unsigned int GRAY300 = Color(0xE1E1E1);
    const unsigned int GRAY400 = Color(0xCACACA);
    const unsigned int GRAY500 = Color(0xB3B3B3);
    const unsigned int GRAY600 = Color(0x8E8E8E);
    const unsigned int GRAY700 = Color(0x707070);
    const unsigned int GRAY800 = Color(0x4B4B4B);
    const unsigned int GRAY900 = Color(0x2C2C2C);
    const unsigned int BLUE400 = Color(0x2680EB);
    const unsigned int BLUE500 = Color(0x1473E6);
    const unsigned int BLUE600 = Color(0x0D66D0);
    const unsigned int BLUE700 = Color(0x095ABA);
    const unsigned int RED400 = Color(0xE34850);
    const unsigned int RED500 = Color(0xD7373F);
    const unsigned int RED600 = Color(0xC9252D);
    const unsigned int RED700 = Color(0xBB121A);
    const unsigned int ORANGE400 = Color(0xE68619);
    const unsigned int ORANGE500 = Color(0xDA7B11);
    const unsigned int ORANGE600 = Color(0xCB6F10);
    const unsigned int ORANGE700 = Color(0xBD640D);
    const unsigned int GREEN400 = Color(0x2D9D78);
    const unsigned int GREEN500 = Color(0x268E6C);
    const unsigned int GREEN600 = Color(0x12805C);
    const unsigned int GREEN700 = Color(0x107154);
    const unsigned int INDIGO400 = Color(0x6767EC);
    const unsigned int INDIGO500 = Color(0x5C5CE0);
    const unsigned int INDIGO600 = Color(0x5151D3);
    const unsigned int INDIGO700 = Color(0x4646C6);
    const unsigned int CELERY400 = Color(0x44B556);
    const unsigned int CELERY500 = Color(0x3DA74E);
    const unsigned int CELERY600 = Color(0x379947);
    const unsigned int CELERY700 = Color(0x318B40);
    const unsigned int MAGENTA400 = Color(0xD83790);
    const unsigned int MAGENTA500 = Color(0xCE2783);
    const unsigned int MAGENTA600 = Color(0xBC1C74);
    const unsigned int MAGENTA700 = Color(0xAE0E66);
    const unsigned int YELLOW400 = Color(0xDFBF00);
    const unsigned int YELLOW500 = Color(0xD2B200);
    const unsigned int YELLOW600 = Color(0xC4A600);
    const unsigned int YELLOW700 = Color(0xB79900);
    const unsigned int FUCHSIA400 = Color(0xC038CC);
    const unsigned int FUCHSIA500 = Color(0xB130BD);
    const unsigned int FUCHSIA600 = Color(0xA228AD);
    const unsigned int FUCHSIA700 = Color(0x93219E);
    const unsigned int SEAFOAM400 = Color(0x1B959A);
    const unsigned int SEAFOAM500 = Color(0x16878C);
    const unsigned int SEAFOAM600 = Color(0x0F797D);
    const unsigned int SEAFOAM700 = Color(0x096C6F);
    const unsigned int CHARTREUSE400 = Color(0x85D044);
    const unsigned int CHARTREUSE500 = Color(0x7CC33F);
    const unsigned int CHARTREUSE600 = Color(0x73B53A);
    const unsigned int CHARTREUSE700 = Color(0x6AA834);
    const unsigned int PURPLE400 = Color(0x9256D9);
    const unsigned int PURPLE500 = Color(0x864CCC);
    const unsigned int PURPLE600 = Color(0x7A42BF);
    const unsigned int PURPLE700 = Color(0x6F38B1);
  }
        //#endif
//#ifdef SPECTRUM_USE_DARK_THEME
  namespace Dark{
    const unsigned int GRAY50 = Color(0x252525);
        const unsigned int GRAY75 = Color(0x2F2F2F);
        const unsigned int GRAY100 = Color(0x323232);
        const unsigned int GRAY200 = Color(0x393939);
        const unsigned int GRAY300 = Color(0x3E3E3E);
        const unsigned int GRAY400 = Color(0x4D4D4D);
        const unsigned int GRAY500 = Color(0x5C5C5C);
        const unsigned int GRAY600 = Color(0x7B7B7B);
        const unsigned int GRAY700 = Color(0x999999);
        const unsigned int GRAY800 = Color(0xCDCDCD);
        const unsigned int GRAY900 = Color(0xFFFFFF);
        const unsigned int BLUE400 = Color(0x2680EB);
        const unsigned int BLUE500 = Color(0x378EF0);
        const unsigned int BLUE600 = Color(0x4B9CF5);
        const unsigned int BLUE700 = Color(0x5AA9FA);
        const unsigned int RED400 = Color(0xE34850);
        const unsigned int RED500 = Color(0xEC5B62);
        const unsigned int RED600 = Color(0xF76D74);
        const unsigned int RED700 = Color(0xFF7B82);
        const unsigned int ORANGE400 = Color(0xE68619);
        const unsigned int ORANGE500 = Color(0xF29423);
        const unsigned int ORANGE600 = Color(0xF9A43F);
        const unsigned int ORANGE700 = Color(0xFFB55B);
        const unsigned int GREEN400 = Color(0x2D9D78);
        const unsigned int GREEN500 = Color(0x33AB84);
        const unsigned int GREEN600 = Color(0x39B990);
        const unsigned int GREEN700 = Color(0x3FC89C);
        const unsigned int INDIGO400 = Color(0x6767EC);
        const unsigned int INDIGO500 = Color(0x7575F1);
        const unsigned int INDIGO600 = Color(0x8282F6);
        const unsigned int INDIGO700 = Color(0x9090FA);
        const unsigned int CELERY400 = Color(0x44B556);
        const unsigned int CELERY500 = Color(0x4BC35F);
        const unsigned int CELERY600 = Color(0x51D267);
        const unsigned int CELERY700 = Color(0x58E06F);
        const unsigned int MAGENTA400 = Color(0xD83790);
        const unsigned int MAGENTA500 = Color(0xE2499D);
        const unsigned int MAGENTA600 = Color(0xEC5AAA);
        const unsigned int MAGENTA700 = Color(0xF56BB7);
        const unsigned int YELLOW400 = Color(0xDFBF00);
        const unsigned int YELLOW500 = Color(0xEDCC00);
        const unsigned int YELLOW600 = Color(0xFAD900);
        const unsigned int YELLOW700 = Color(0xFFE22E);
        const unsigned int FUCHSIA400 = Color(0xC038CC);
        const unsigned int FUCHSIA500 = Color(0xCF3EDC);
        const unsigned int FUCHSIA600 = Color(0xD951E5);
        const unsigned int FUCHSIA700 = Color(0xE366EF);
        const unsigned int SEAFOAM400 = Color(0x1B959A);
        const unsigned int SEAFOAM500 = Color(0x20A3A8);
        const unsigned int SEAFOAM600 = Color(0x23B2B8);
        const unsigned int SEAFOAM700 = Color(0x26C0C7);
        const unsigned int CHARTREUSE400 = Color(0x85D044);
        const unsigned int CHARTREUSE500 = Color(0x8EDE49);
        const unsigned int CHARTREUSE600 = Color(0x9BEC54);
        const unsigned int CHARTREUSE700 = Color(0xA3F858);
        const unsigned int PURPLE400 = Color(0x9256D9);
        const unsigned int PURPLE500 = Color(0x9D64E1);
        const unsigned int PURPLE600 = Color(0xA873E9);
        const unsigned int PURPLE700 = Color(0xB483F0);
        }
//#endif
  }

  void pdm_style_visual_studio()
  {
    // Visual Studio style by MomoDeve from ImThemes
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6000000238418579f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 0.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 0.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.5921568870544434f, 0.5921568870544434f, 0.5921568870544434f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.3058823645114899f, 0.3058823645114899f, 0.3058823645114899f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.3058823645114899f, 0.3058823645114899f, 0.3058823645114899f, 1.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2156862765550613f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2156862765550613f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2156862765550613f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.321568638086319f, 0.321568638086319f, 0.3333333432674408f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.3529411852359772f, 0.3529411852359772f, 0.3725490272045135f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.3529411852359772f, 0.3529411852359772f, 0.3725490272045135f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2156862765550613f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2156862765550613f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.3058823645114899f, 0.3058823645114899f, 0.3058823645114899f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3058823645114899f, 0.3058823645114899f, 0.3058823645114899f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.3058823645114899f, 0.3058823645114899f, 0.3058823645114899f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2156862765550613f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.321568638086319f, 0.321568638086319f, 0.3333333432674408f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.1137254908680916f, 0.5921568870544434f, 0.9254902005195618f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.0f, 0.4666666686534882f, 0.7843137383460999f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1490196138620377f, 1.0f);
  }

  void adobe_spectrum_light () {
    using namespace ImGui;
    ImGuiStyle* style = &ImGui::GetStyle();
    style->GrabRounding = 4.0f;

    ImVec4* colors = style->Colors;
    colors[ImGuiCol_Text] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY800); // text on hovered controls is gray900
    colors[ImGuiCol_TextDisabled] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY500);
    colors[ImGuiCol_WindowBg] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY100);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY50); // not sure about this. Note: applies to tooltips too.
    colors[ImGuiCol_Border] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY300);
    colors[ImGuiCol_BorderShadow] = ColorConvertU32ToFloat4(Spectrum::Static::NONE); // We don't want shadows. Ever.
    colors[ImGuiCol_FrameBg] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY75); // this isnt right, spectrum does not do this, but it's a good fallback
    colors[ImGuiCol_FrameBgHovered] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY50);
    colors[ImGuiCol_FrameBgActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY200);
    colors[ImGuiCol_TitleBg] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY300); // those titlebar values are totally made up, spectrum does not have this.
    colors[ImGuiCol_TitleBgActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY200);
    colors[ImGuiCol_TitleBgCollapsed] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY400);
    colors[ImGuiCol_MenuBarBg] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY100);
    colors[ImGuiCol_ScrollbarBg] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY100); // same as regular background
    colors[ImGuiCol_ScrollbarGrab] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY400);
    colors[ImGuiCol_ScrollbarGrabHovered] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY600);
    colors[ImGuiCol_ScrollbarGrabActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY700);
    colors[ImGuiCol_CheckMark] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE500);
    colors[ImGuiCol_SliderGrab] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY700);
    colors[ImGuiCol_SliderGrabActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY800);
    colors[ImGuiCol_Button] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY75); // match default button to Spectrum::Light's 'Action Button'.
    colors[ImGuiCol_ButtonHovered] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY50);
    colors[ImGuiCol_ButtonActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY200);
    colors[ImGuiCol_Header] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE400);
    colors[ImGuiCol_HeaderHovered] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE500);
    colors[ImGuiCol_HeaderActive] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE600);
    colors[ImGuiCol_Separator] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY400);
    colors[ImGuiCol_SeparatorHovered] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY600);
    colors[ImGuiCol_SeparatorActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY700);
    colors[ImGuiCol_ResizeGrip] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY400);
    colors[ImGuiCol_ResizeGripHovered] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY600);
    colors[ImGuiCol_ResizeGripActive] = ColorConvertU32ToFloat4(Spectrum::Light::GRAY700);
    colors[ImGuiCol_PlotLines] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE400);
    colors[ImGuiCol_PlotLinesHovered] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE600);
    colors[ImGuiCol_PlotHistogram] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE400);
    colors[ImGuiCol_PlotHistogramHovered] = ColorConvertU32ToFloat4(Spectrum::Light::BLUE600);
    colors[ImGuiCol_TextSelectedBg] = ColorConvertU32ToFloat4((Spectrum::Light::BLUE400 & 0x00FFFFFF) | 0x33000000);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ColorConvertU32ToFloat4((Spectrum::Light::GRAY900 & 0x00FFFFFF) | 0x0A000000);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
  }

  void adobe_spectrum_dark () {
    using namespace ImGui;
    ImGuiStyle* style = &ImGui::GetStyle();
    style->GrabRounding = 4.0f;

    ImVec4* colors = style->Colors;
    colors[ImGuiCol_Text] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY800); // text on hovered controls is gray900
    colors[ImGuiCol_TextDisabled] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY500);
    colors[ImGuiCol_WindowBg] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY100);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY50); // not sure about this. Note: applies to tooltips too.
    colors[ImGuiCol_Border] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY300);
    colors[ImGuiCol_BorderShadow] = ColorConvertU32ToFloat4(Spectrum::Static::NONE); // We don't want shadows. Ever.
    colors[ImGuiCol_FrameBg] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY75); // this isnt right, spectrum does not do this, but it's a good fallback
    colors[ImGuiCol_FrameBgHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY50);
    colors[ImGuiCol_FrameBgActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY200);
    colors[ImGuiCol_TitleBg] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY300); // those titlebar values are totally made up, spectrum does not have this.
    colors[ImGuiCol_TitleBgActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY200);
    colors[ImGuiCol_TitleBgCollapsed] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY400);
    colors[ImGuiCol_MenuBarBg] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY100);
    colors[ImGuiCol_ScrollbarBg] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY100); // same as regular background
    colors[ImGuiCol_ScrollbarGrab] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY400);
    colors[ImGuiCol_ScrollbarGrabHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY600);
    colors[ImGuiCol_ScrollbarGrabActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY700);
    colors[ImGuiCol_CheckMark] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE500);
    colors[ImGuiCol_SliderGrab] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY700);
    colors[ImGuiCol_SliderGrabActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY800);
    colors[ImGuiCol_Button] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY75); // match default button to Spectrum::Dark's 'Action Button'.
    colors[ImGuiCol_ButtonHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY50);
    colors[ImGuiCol_ButtonActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY200);
    colors[ImGuiCol_Header] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE400);
    colors[ImGuiCol_HeaderHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE500);
    colors[ImGuiCol_HeaderActive] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE600);
    colors[ImGuiCol_Separator] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY400);
    colors[ImGuiCol_SeparatorHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY600);
    colors[ImGuiCol_SeparatorActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY700);
    colors[ImGuiCol_ResizeGrip] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY400);
    colors[ImGuiCol_ResizeGripHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY600);
    colors[ImGuiCol_ResizeGripActive] = ColorConvertU32ToFloat4(Spectrum::Dark::GRAY700);
    colors[ImGuiCol_PlotLines] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE400);
    colors[ImGuiCol_PlotLinesHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE600);
    colors[ImGuiCol_PlotHistogram] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE400);
    colors[ImGuiCol_PlotHistogramHovered] = ColorConvertU32ToFloat4(Spectrum::Dark::BLUE600);
    colors[ImGuiCol_TextSelectedBg] = ColorConvertU32ToFloat4((Spectrum::Dark::BLUE400 & 0x00FFFFFF) | 0x33000000);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ColorConvertU32ToFloat4((Spectrum::Dark::GRAY900 & 0x00FFFFFF) | 0x0A000000);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
  }
} // PDM

