
#include "imgui.h"
#include "pdm.h" // PDM::Runtime
#include "pdm_net.h" // get_json()
#include "pdm-network.h"

namespace PDM::Components {
  bool net_debug(PDM::Runtime* rt){
    static char email[2048], password[2048], wtptr[2048]={0};
    static std::string j_str;

    static struct NetWriter wt;
    wt.readptr = wtptr; wt.sizeleft = 2048;

    ImGui::Text("Password length: %d", strlen(password));
    ImGui::Text("Json: \"%s\"", j_str.c_str());
    ImGui::InputText("Email", email, 2048, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Password",    password, 2048, 0);
    if (ImGui::Button("login")) {
      std::map<std::string,std::string> data {{"umail",email},{"upw",password}};
      j_str = PDM::network::get_json(data);
      rt->signin_action(j_str, &wt);
    }
    ImGui::Separator();

    const float footer_height_to_reserve1 =  ImGui::GetFrameHeightWithSpacing();
    if (ImGui::BeginChild("ServerResponse", ImVec2(0, 50.0f), false, ImGuiWindowFlags_HorizontalScrollbar)) {
      ImGui::Text("Server Response");
      ImGui::Text("\"%s\"", wt.readptr);
    }
    ImGui::EndChild();
    ImGui::Separator();
    const float footer_height_to_reserve2 =  ImGui::GetFrameHeightWithSpacing();
    if (ImGui::BeginChild("ResponseDetail", ImVec2(0, 50.0f), false, ImGuiWindowFlags_HorizontalScrollbar)) {
      ImGui::Text("Response Detail");
      ImGui::Text("Response Size: %d", wt.sizeleft);
    }
    ImGui::EndChild();
    ImGui::Separator();

    return true;
  }
}