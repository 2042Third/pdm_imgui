//
// Created by Mike Yang on 11/25/2022.
//

#include "pdm_database.h"
//#include "crypto/pdmCryptoDB.hpp"
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
  }

  pdm_database::~pdm_database() = default;
}

int PDM::pdm_database::open_db(char *name) {
  change(PDM::Status::LOADING);
//  cryptosqlite::setCryptoFactory([] (std::unique_ptr<IDataCrypt> &crypt) {
//    crypt.reset(new pdm_crypto_db());
//  });
//  rc = sqlite3_open_encrypted(name, &db, name, 3);
  rc = sqlite3_open_v2(name, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_URI, NULL);
  change(PDM::Status::OPEN);
  if( rc ){
    change(PDM::Status::PDM_ERROR);
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
int PDM::pdm_database::execute(char *input) {
  change(PDM::Status::LOADING);
  rc = sqlite3_exec(db, input, callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    change(PDM::Status::PDM_ERROR);
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    return 0;
  }
  last_command = input;
  change(PDM::Status::OPEN);
  return 1;
}
