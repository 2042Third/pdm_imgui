//
// Created by Yi Yang on 12/13/2022.
//

#include <pdm_net.h>
#include <nlohmann/json.hpp>
#include <pdm_network/pdm-network.h>

namespace PDM {

  static size_t read_callback(char *dest, size_t size, size_t nmemb, void *userp)
  {
    struct WriteThis *wt = (struct WriteThis *)userp;
    size_t buffer_size = size*nmemb;
    if(wt->sizeleft) {
      /* copy as much as possible from the source to the destination */
      size_t copy_this_much = wt->sizeleft;
      if(copy_this_much > buffer_size)
        copy_this_much = buffer_size;
      memcpy(dest, wt->readptr, copy_this_much);
      wt->readptr += copy_this_much;
      wt->sizeleft -= copy_this_much;
      return copy_this_much; /* we copied this many bytes */
    }
    return 0; /* no more data left to deliver */
  }

  int network::signin_action(const std::string&a) {

    post(a,actions.signinURL);
    return 1;
  }

  void network::post (const std::string& a,const std::string& b) {

    std::string rstr;
    rstr.resize(2048);
    struct WriteThis wt;
    wt.readptr = rstr.data();
    wt.sizeleft = rstr.size();
    pdm_network::post(a,b, read_callback, &wt);
  }


  network::network() {
  }

  network::~network() {

  }


} // PDM