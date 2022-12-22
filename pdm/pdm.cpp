// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "pdm.h"

namespace PDM {
  /**
   * Constructor
   * */
  Runtime::Runtime(){
    db = new pdm_database();
    set_db(db);
  }
  /**
   * Destructor
   * */
  Runtime::~Runtime() {
    delete db;
  }


} // PDM