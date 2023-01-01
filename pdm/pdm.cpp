// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "pdm.h"
#include "misc/base64.h"
#include "misc/md5.h"
#include <filesystem>

namespace PDM {
  /**
   * Checks if user exists on this computer.
   * Locations:
   *    "./user/${file_names}/${file_names}"
   *    "./user/${file_names}/data/${file_names}.data"
   * */
  int Runtime::get_user_loc (const std::string& file_names) {
    conf_loc = "./user/"+file_names+"/"+file_names;
    data_loc = "./user/"+file_names+"/data/"+file_names+".data";
    const std::filesystem::path confp(conf_loc), datap(data_loc);
    // Check the two paths
    return std::filesystem::exists(confp) && std::filesystem::exists(datap);
  }

  int Runtime::signin_action(const std::string&a, NetWriter* wt_in, const char* password){
    std::string ps = password;
    struct NetCallBack_ {
      static size_t _callback(char *data, size_t size, size_t nmemb, void *userp) {
        auto *wt = (struct NetObj *)userp;
        if (wt->userinfo.status == "success") { // The sign in is successful
          MD5 md5; md5.add(wt->userinfo.email.c_str(),wt->userinfo.email.size());
          std::string file_names = md5.getHash(); // md5 encode user email
          // Check or create the appropriate db
          auto*rt = (PDM::Runtime*)wt->pdm_runtime;
          if (!rt->get_user_loc(file_names)){
            const std::filesystem::path confp(rt->conf_loc), datap(rt->data_loc);
            std::filesystem::create_directories(confp.parent_path());
            std::filesystem::create_directories(datap.parent_path());
            // TODO: What to do when user first use this computer to login
          }
          std::cout<< "conf_loc: "<< rt->conf_loc<<std::endl;
          std::cout<< "data_loc: "<< rt->data_loc<<std::endl;
          rt->user_conf->open_db(rt->conf_loc.c_str(),"pdmnotes",8);
          rt->user_data->open_db(rt->data_loc.c_str(),wt->data.c_str(),wt->data.size());
        } else {
          // TODO: Deal with the failed login
        }
        return post_callback_signin(data,  size,  nmemb, userp); /* we copied this many bytes */
      }
    };
    wt_in->pdm_runtime = this;
    wt_in->data = ps;
    signin_post(a,wt_in,NetCallBack_::_callback); // Call network post for Sign In action

    return 1;
  }

  /**
   * Constructor
   * */
  Runtime::Runtime(){
    db = new pdm_database(); // Create the db used for debug, also store the most recent data
    user_conf = new pdm_database(); // Create config db for user
    user_data = new pdm_database(); // Create config db for user

    set_db(db);
  }
  /**
   * Destructor
   * */
  Runtime::~Runtime() {
    delete db;
    delete user_data;
    delete user_conf;
  }


} // PDM