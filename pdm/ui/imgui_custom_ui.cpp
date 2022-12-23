//
// Created by Yi Yang on 12/23/2022.
//

#include "imgui_custom_ui.h"
#include "themes/pdm_colors.h"

namespace ImGui {
  bool SingleLineSelectableText(const char * label, const char* buffer, size_t buffer_size, int original_color){
    if(!original_color)ImGui::PushStyleColor(ImGuiCol_FrameBg,
        ImGui::ColorConvertU32ToFloat4(PDM::THEME::COLOR::Dark::GRAY200)); // push color
    ImGui::InputText(label, (char*)buffer, buffer_size, ImGuiInputTextFlags_ReadOnly);
    if(!original_color)ImGui::PopStyleColor(); // Pop color
    return true;
  }

} // ImGui