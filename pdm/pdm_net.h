//
// Created by Yi Yang on 12/13/2022.
//

#ifndef PDM_PLATFORMS_UI_PDM_NET_H
#define PDM_PLATFORMS_UI_PDM_NET_H

#include <string>

namespace PDM {

  class network {
    struct notes{
      const std::string GetHeadsType = "heads";
      const std::string GetNoteType = "retrieve";
      const std::string GetNewNoteType = "new";
      const std::string UpdateNoteType = "update";
      const std::string DeleteNoteType = "delete";
    };
    struct actions {
      const std::string pdmRootURL = "https://pdm.pw";
      const std::string signURL = pdmRootURL+"/auth/signin";
      const std::string signupURL = pdmRootURL + "/auth/signup";
      const std::string notesGetHeadsURL = pdmRootURL + "/auth/note";
    };

  };

} // PDM

#endif //PDM_PLATFORMS_UI_PDM_NET_H
