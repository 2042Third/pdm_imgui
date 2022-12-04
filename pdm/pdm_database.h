//
// Created by Mike Yang on 11/25/2022.
//

#ifndef PDM_PLATFORMS_UI_PDM_DATABASE_H
#define PDM_PLATFORMS_UI_PDM_DATABASE_H

#include "pdm_status.h"
#include "sqlite3.h"
//#include "cryptosqlite/cryptosqlite.h"

namespace PDM
{
class pdm_database : public Status{
public:
  pdm_database();
  ~pdm_database();

  int open_db(char* name);
  int close_db(char* name);
  int execute(char *input);

  sqlite3 *db{};
//  cryptosqlite enc_db;
  char *zErrMsg = 0;
  int rc;
   std::string last_command ;
};

}


#endif //PDM_PLATFORMS_UI_PDM_DATABASE_H
