//
// Created by Mike Yang on 11/25/2022.
//

#include "pdm_database.h"
#include <sqlite3.h>
#include <string>

namespace PDM {
  static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
  }

  pdm_database::pdm_database() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string pdm_db = "PDM";
    change(PDM::Status::LOADING);
    rc = sqlite3_open(pdm_db.data(), &db);
    change(PDM::Status::OPEN);
    if( rc ){
      change(PDM::Status::ERROR);
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return;
    }
//    rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
//    if( rc!=SQLITE_OK ){
//              change(5);
//              fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//      }
    sqlite3_close(db);
    change(PDM::Status::CLOSED);
  }

  pdm_database::~pdm_database() {

  }
}