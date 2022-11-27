//
// Created by Mike Yang on 11/25/2022.
//

#include "pdm_database.h"
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

  pdm_database::~pdm_database() = default;
}

int PDM::pdm_database::open_db(char *name) {
  change(PDM::Status::LOADING);
  rc = sqlite3_open(name, &db);
  change(PDM::Status::OPEN);
  if( rc ){
    change(PDM::Status::ERROR);
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 0;
  }
  return 1;
}

int PDM::pdm_database::close_db(char *name) {
  change(PDM::Status::LOADING);
  sqlite3_close(db);
  change(PDM::Status::CLOSED);
  return 1;
}
