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
    struct c {
      static size_t _callback(char *data, size_t size, size_t nmemb, void *userp) {

        return post_callback_signin(data,  size,  nmemb, userp); /* we copied this many bytes */
      }
    };

    signin_post(a,wt_in,c::_callback); // Call network post for Sign In action
    if (wt.userinfo.status == "success") { // The sign in is successful
      MD5 md5; md5.add(wt.userinfo.email.c_str(),wt.userinfo.email.size());
      std::string file_names = md5.getHash(); // md5 encode user email
      // Check or create the appropriate db
      if (!get_user_loc(file_names)){
        const std::filesystem::path confp(conf_loc), datap(data_loc);
        std::filesystem::create_directories(confp.parent_path());
        std::filesystem::create_directories(datap.parent_path());
        // TODO: What to do when user first use this computer to login
      }
      std::cout<< "conf_loc: "<< conf_loc<<std::endl;
      std::cout<< "data_loc: "<< data_loc<<std::endl;
      user_conf->open_db(conf_loc.c_str(),"pdmnotes",8);
      user_data->open_db(data_loc.c_str(),ps.c_str(),ps.size());
    } else {
      // TODO: Deal with the failed login
    }
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