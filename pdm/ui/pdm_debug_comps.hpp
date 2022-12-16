
#include "imgui.h"
#include "pdm.h" // PDM::Runtime
#include "pdm_net.h" // get_json()
#include "pdm-network.h"

namespace PDM::Components {
  bool net_debug(PDM::Runtime* rt){
    static char email[2048], password[2048];
    static std::string j_str;

    ImGui::Text("Password length: %d", strlen(password));
    ImGui::Text("Json: \"%s\"", j_str.c_str());
    ImGui::InputText("Email", email, 2048, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Password",    password, 2048, 0);
    if (ImGui::Button("login")) {
      std::map<std::string,std::string> data {{"umail",email},{"upw",password}};
      j_str = PDM::network::get_json(data);
      rt->signin_action(j_str, &rt->wt);
    }
    ImGui::Separator();

    const float footer_height_to_reserve1 =  ImGui::GetFrameHeightWithSpacing();
    ImGui::PushStyleColor(ImGuiCol_WindowBg,ImGui::GetStyle().Colors[ImGuiCol_Button]); // Change output view color
    if (ImGui::BeginChild("ServerResponse", ImVec2(0, 100.0f), false, ImGuiWindowFlags_HorizontalScrollbar)) {
      ImGui::Text("Server Response");
      ImGui::TextWrapped("\"%s\"", rt->wt.readptr.c_str());
    }
    ImGui::EndChild();
    ImGui::PopStyleColor(1); // Change back the output color

    ImGui::Separator();
    const float footer_height_to_reserve2 =  ImGui::GetFrameHeightWithSpacing();
    if (ImGui::BeginChild("ResponseDetail", ImVec2(0, 100.0f), false, ImGuiWindowFlags_HorizontalScrollbar)) {
      ImGui::Text("Response Detail");
      ImGui::Text("Response Size: %d", rt->wt.sizeleft);
    }
    ImGui::EndChild();
    ImGui::Separator();

    return true;
  }
}