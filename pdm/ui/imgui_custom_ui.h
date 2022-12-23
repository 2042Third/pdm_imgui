//
// Created by Yi Yang on 12/23/2022.
//

#ifndef PDM_PLATFORMS_UI_IMGUI_CUSTOM_UI_H
#define PDM_PLATFORMS_UI_IMGUI_CUSTOM_UI_H

#include "imgui.h"

namespace ImGui {

  bool SingleLineSelectableText(const char * label, const char* buffer, size_t buffer_size, int original_color=0);

} // ImGui

#endif //PDM_PLATFORMS_UI_IMGUI_CUSTOM_UI_H
