//
// Created by Yi Yang on 12/13/2022.
//

#include "pdm_net.h"
#include "pdm_platforms_ui/pdm/lib/json/single_include/nlohmann/json.hpp"
#include "pdm_platforms_ui/pdm/lib/pdm_network/pdm-network.h"
#include "net_convert.h"
#include <iostream>

namespace PDM {
  using json = nlohmann::json;

  static size_t post_callback( char *data, size_t size, size_t nmemb, void *userp){
    auto *wt = (struct NetObj *)userp;
    wt->readptr = std::move(std::string(data,nmemb));
    wt->js = json::parse(wt->readptr);
    std::cout<<"JSON: "<<wt->js<<std::endl;
    PDM::network::get_userinfo(wt->js,wt->userinfo);
    return nmemb; /* we copied this many bytes */
  }

  int network::signin_action(const std::string&a, NetWriter* wt_in) {
    post(a,actions.signinURL,  wt_in);
    return 1;
  }

  void network::post (const std::string& a, const std::string& b, NetWriter* wt) {
    pdm_network::post(a,b, post_callback, wt);
  }


  network::network() {
  }

  network::~network() {

  }

  void network::get_userinfo(const json &j,UserInfo& userinfo) {
    PDM::net_convert::convert(j,userinfo);
  }


} // PDM