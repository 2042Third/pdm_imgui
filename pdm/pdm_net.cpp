//
// Created by Yi Yang on 12/13/2022.
//

#include <pdm_net.h>
#include <nlohmann/json.hpp>

namespace PDM {


  int network::signin_action(const std::string&a) {

//    net.post(a, actions.signinURL);
    return 1;
  }

//  template<typename T>
//  std::string network::get_json (std::map<T,T>&a){
//    using json = nlohmann::json;
//    json j(a);
//    std::string signin_data =to_string(j);
//    return std::move(signin_data);
//  }

  network::network() {
  }

  network::~network() {

  }


} // PDM