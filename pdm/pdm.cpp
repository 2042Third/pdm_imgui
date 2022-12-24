// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "pdm.h"

namespace PDM {
  /**
   * Constructor
   * */
  Runtime::Runtime(){
    db = new pdm_database(); // Create the db used for debug, also store the most recent data
    user_conf = new pdm_database(); // Create config db for user

    set_db(db);
  }
  /**
   * Destructor
   * */
  Runtime::~Runtime() {
    delete db;
  }


} // PDM