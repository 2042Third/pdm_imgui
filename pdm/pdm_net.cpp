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
    size_t buffer_size = size*nmemb;
    if(wt->sizeleft) {
      wt->readptr = std::move(std::string(data,buffer_size));
      std::cout<< "Made copy => "<< wt->readptr<<std::endl;
      wt->readptr += buffer_size;
      wt->sizeleft -= buffer_size;
      return buffer_size; /* we copied this many bytes */
    }
    return 0; /* no more data left to deliver */
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