//
// Created by Yi Yang on 12/13/2022.
//

#include <pdm_net.h>
#include <nlohmann/json.hpp>
#include <pdm_network/pdm-network.h>
#include <iostream>

namespace PDM {

  static size_t read_callback( char *data, size_t size, size_t nmemb, void *userp)
  {
    auto *wt = (struct NetWriter *)userp;
    wt->readptr = std::move(std::string(data,nmemb));
    return nmemb; /* we copied this many bytes */
  }

  int network::signin_action(const std::string&a, NetWriter* wt) {

    post(a,actions.signinURL,  wt);
    return 1;
  }

  void network::post (const std::string& a, const std::string& b, NetWriter* wt) {
    pdm_network::post(a,b, read_callback, wt);
  }


  network::network() {
  }

  network::~network() {

  }


} // PDM