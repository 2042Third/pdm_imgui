
#include "imgui.h"
#include "pdm.h" // PDM::Runtime
#include "pdm_net.h" // get_json()

namespace PDM::Components {
  bool net_debug(PDM::Runtime* rt){
    static char email[2048], password[2048];
    static std::string j_str = "";
    ImGui::Text("Password length: %d", strlen(password));
    ImGui::Text("Json: \"%s\"", j_str.c_str());
    ImGui::InputText("Email", email, 2048, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Password",    password, 2048, 0);
    if (ImGui::Button("login")) {
      std::map<std::string,std::string> data {{"umail",email},{"upw",password}};
      j_str = PDM::network::get_json(data);
      rt->signin_action(j_str);
    }
    return true;
  }
}