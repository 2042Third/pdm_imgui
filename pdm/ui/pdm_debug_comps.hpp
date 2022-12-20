
#include "imgui.h"
#include "pdm.h" // PDM::Runtime
#include "pdm_platforms_ui/pdm/handler/pdm_net.h" // get_json()
#include "pdm-network.h"
#include "handler/pdm_net_type.h"

namespace PDM::Components {
  bool net_debug(PDM::Runtime* rt){
    static char email[2048], password[2048];
    static std::string j_str;

    ImGui::Text("Password length: %d", strlen(password));
    ImGui::Text("Json: \"%s\"", j_str.c_str());
    ImGui::InputText("Email", email, 2048, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Password",    password, 2048, 0);
    if (ImGui::Button("login")|| (ImGui::IsWindowFocused()&&ImGui::IsKeyReleased(ImGuiKey_Enter) )) {
      std::map<std::string,std::string> data=PDM::pdm_net_type::get_signin_json(email,password);
      j_str = PDM::network::get_json(data);
      rt->signin_action(j_str, &rt->wt);
    }
    ImGui::Separator();
    const float footer_height_to_reserve1 =  ImGui::GetFrameHeightWithSpacing();
    ImGui::PushStyleColor(ImGuiCol_WindowBg,ImGui::GetStyle().Colors[ImGuiCol_Button]); // Change output view color
    if (ImGui::BeginChild("ServerResponse", ImVec2(0, 100.0f), false
                          , ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_AlwaysVerticalScrollbar)) {
      ImGui::Text("Server Response");
      ImGui::Separator();
      ImGui::InputTextMultiline("##source", ( char*)rt->wt.readptr.c_str(), rt->wt.readptr.size()
                                , ImVec2(-FLT_MIN, 100.0f - ImGui::GetTextLineHeight()), ImGuiInputTextFlags_ReadOnly);
      ImGui::Separator();
    }
    ImGui::EndChild();
    ImGui::PopStyleColor(1); // Change back the output color

    ImGui::Separator();
    const float footer_height_to_reserve2 =  ImGui::GetFrameHeightWithSpacing();
    if (ImGui::BeginChild("ResponseDetail", ImVec2(0, 100.0f), false, ImGuiWindowFlags_HorizontalScrollbar)) {
      ImGui::Text("Response Detail");
      ImGui::Text("Status: %d", rt->wt.js.contains("status"));
      if (rt->wt.js.contains("status")) {
        for (auto& [key, value] : rt->wt.js.items()) {
          if (value) ImGui::Text(" %s ", key.c_str());
//          if (value) ImGui::Text(" %s: %s ", key.c_str(),value.get<std::string>().c_str());
        }
      }
    }
    ImGui::EndChild();
    ImGui::Separator();

    return true;
  }
}