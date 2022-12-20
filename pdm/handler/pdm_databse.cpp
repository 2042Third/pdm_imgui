//
// Created by Mike Yang on 11/25/2022.
//

#include "pdm_database.h"
#include "crypto/pdmCryptoDB.hpp"
#include <memory>
#include <string>

namespace PDM {
  static int callback(void *ptr, int argc, char **argv, char **azColName) {
    using tbl_type = PDM::pdm_database::return_table;
    tbl_type* table = static_cast<tbl_type*>(ptr);

    int i;
    std::vector<std::string> tmp;
    if(table->argc==0){ // first time recording
      table->argc = argc;
      for (unsigned f =0 ;f<argc;f++)
        table->col_name.push_back(std::move(std::string(azColName[f])));
    }
    for (i = 0; i < argc; i++) {
      tmp.push_back(std::move(std::string(argv[i])));
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    table->argv.push_back(std::move(tmp));
    printf("\n");
    return 0;
  }

  pdm_database::pdm_database() {
  }

  pdm_database::~pdm_database() {

  }
}

int PDM::pdm_database::open_db(char *name, char*pas, int pas_size) {
  change(PDM::Status::LOADING);
  cryptosqlite::setCryptoFactory([] (std::unique_ptr<IDataCrypt> &crypt) {
    crypt = std::make_unique<pdm_crypto_db>();
  });
  rc = sqlite3_open_encrypted(name, &db, pas, pas_size); // open the encrypted database
//  rc = sqlite3_open_v2(name, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_URI, NULL);
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
  reset(&current_display_table);
  rc = sqlite3_exec(db, input, callback, &current_display_table, &zErrMsg);
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
