//
// Created by Yi Yang on 12/19/2022.
//

#ifndef PDM_PLATFORMS_UI_PDM_NET_TYPE_H
#define PDM_PLATFORMS_UI_PDM_NET_TYPE_H

#include <string>
#include <map>

namespace PDM {
  class pdm_net_type {
  public:
    static std::map<std::string,std::string>get_signin_json(const char* email, const char* password);
  };
}

#endif //PDM_PLATFORMS_UI_PDM_NET_TYPE_H
