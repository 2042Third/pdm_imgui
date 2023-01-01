﻿// CMakeProject1.cpp : Defines the entry point for the application.
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
   * @params conf - configuration, default 1; 1 = user configuration, else user data configuration
   * */
  int Runtime::get_user_loc (const std::string& file_names,int conf) {
    if (conf == 1 ) {
      conf_loc = "./user/" + file_names + "/" + file_names;
      const std::filesystem::path confp(conf_loc);
      return std::filesystem::exists(confp);
    }
    else if (conf == 0) {
      data_loc = "./user/" + file_names + "/data/" + file_names + ".data";
      const std::filesystem::path datap(data_loc);
      return std::filesystem::exists(datap);
    }
    return 0;
  }

  int Runtime::signin_action(const std::string&a, NetWriter* wt_in, const char* password,const char* email){
    std::string ps = password, user_mail = email;
    struct NetCallBack_ {
      static size_t _callback(char *data, size_t size, size_t nmemb, void *userp) {
        int callback_out = (int) post_callback_signin(data,  size,  nmemb, userp);
        auto *wt = (struct NetObj *)userp;
        auto*rt = (PDM::Runtime*)wt->pdm_runtime;
        if (rt->wt.userinfo.status == "success") { // The sign in is successful
          MD5 md5; md5.add(wt->userinfo.email.c_str(),wt->userinfo.email.size());
          std::string file_names = md5.getHash(); // md5 encode user email
          // Check or create the appropriate db
          if (!rt->get_user_loc(file_names,0)){
            const std::filesystem::path confp(rt->conf_loc), datap(rt->data_loc);
            std::filesystem::create_directories(datap.parent_path()); // Create user data dir.
            // TODO: What to do when user first use this computer to login
          }
          std::cout<< "data_loc: "<< rt->data_loc<<std::endl;
          rt->user_data->open_db(rt->data_loc.c_str(),wt->data.c_str(),wt->data.size());
        } else {
          std::cout<< "Unsuccessful callback."<<std::endl;
          // TODO: Deal with the failed login
        }
        return callback_out; /* we copied this many bytes */
      }
    };
    std::cout<<"User email: "<< wt.userinfo.email<< std::endl;
    MD5 md5; md5.add(user_mail.c_str(),user_mail.size());
    std::string file_names = md5.getHash();
    get_user_loc(file_names);
    const std::filesystem::path confp(conf_loc);
    std::filesystem::create_directories(confp.parent_path()); // Create user config dir
    std::cout<< "conf_loc: "<< conf_loc<<std::endl;
    user_conf->open_db(conf_loc.c_str(),"pdmnotes",8); // Make local user configurations
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