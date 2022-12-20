//
// Created by Yi Yang on 12/13/2022.
//

#ifndef PDM_PLATFORMS_UI_PDM_NET_H
#define PDM_PLATFORMS_UI_PDM_NET_H

#include <string>
#include "pdm_platforms_ui/pdm/lib/json/single_include/nlohmann/json.hpp"
#include <map>
#include "pdm-network.h"

struct NetObj:NetWriter {
  std::string readptr;
  size_t sizeleft;
  nlohmann::json js;
};
namespace PDM {

  class network {
    using json = nlohmann::json;
  public:
    struct notes{
      const std::string GetHeadsType = "heads";
      const std::string GetNoteType = "retrieve";
      const std::string GetNewNoteType = "new";
      const std::string UpdateNoteType = "update";
      const std::string DeleteNoteType = "delete";
    };
    struct actions {
      const std::string pdmRootURL = "https://pdm.pw";
      const std::string signinURL = pdmRootURL+"/auth/signin";
      const std::string signupURL = pdmRootURL + "/auth/signup";
      const std::string notesGetHeadsURL = pdmRootURL + "/auth/note";
    };


    static void post (const std::string& a, const std::string& b, NetWriter* wt);
    template<typename T>
    static std::string get_json (std::map<T,T>&a) {
      json j(a);
      std::string signin_data =to_string(j);
      return std::move(signin_data);
    }

    int  signin_action(const std::string&a, NetWriter* wt) ;

    network();
    ~network();

    const actions actions;
    const notes notes;
    struct NetObj wt; // store the most recent network return callback

  private:
//    pdm_network net;
  };

} // PDM

#endif //PDM_PLATFORMS_UI_PDM_NET_H