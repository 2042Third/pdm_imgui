//
// Created by Yi Yang on 12/13/2022.
//

#include <pdm_net.h>
#include <nlohmann/json.hpp>

namespace PDM {


  int network::signin_action(const std::string &a) {
    pdm_network::post(a, actions.signinURL);
    return 1;
  }

  network::network() {
  }

  network::~network() {

  }


} // PDM