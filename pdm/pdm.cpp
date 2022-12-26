// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "pdm.h"
#include "misc/base64.h"
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

  int Runtime::signin_action(const std::string&a, NetWriter* wt_in, const std::string & ps){
    signin_post(a,wt_in); // Call network post for Sign In action
    if (wt.userinfo.status == "success") { // The sign in is successful
      std::string file_names = base64_encode(wt.userinfo.email,true); // base 64 url encode user email
      // Check or create the appropriate db
      if (!get_user_loc(file_names)){
        const std::filesystem::path confp(conf_loc), datap(data_loc);
        std::filesystem::create_directories(confp.parent_path());
        std::filesystem::create_directories(datap.parent_path());
        // TODO: What to do when user first use this computer to login
      }
      user_conf->open_db(conf_loc.c_str(),ps.c_str(),ps.size());
    } else {
      // TODO: Deal with the failed login
    }
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