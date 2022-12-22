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

int PDM::pdm_database::execute_note_heads(const nlohmann::json&j) {
  sqlite3_stmt* stmt = 0;
  rc = sqlite3_prepare_v2( db, add_note_head.c_str(), -1, &stmt, 0 );

//  Optional, but will most likely increase performance.
  rc = sqlite3_exec( db, "BEGIN TRANSACTION", 0, 0, 0 );

  for ( auto&i: j["content"] ) {
    //  Binding integer values in this example.
    //  Bind functions for other data-types are available - see end of post.

    //  Bind-parameter indexing is 1-based.
    rc = sqlite3_bind_int( stmt, 1, int_you_wish_to_bind ); // Bind first parameter.
    rc = sqlite3_bind_int( stmt, 2, int_you_wish_to_bind ); // Bind second parameter.

    //  Reading interger results in this example.
    //  Read functions for other data-types are available - see end of post.
    while ( sqlite3_step( stmt ) == SQLITE_ROW ) { // While query has result-rows.
      //  In your example the column count will be 1.
      for ( int colIndex = 0; colIndex < sqlite3_column_count( stmt ); colIndex++ ) {
        int result = sqlite3_column_int( stmt, colIndex );
        //  Do something with the result.
      }
    }
    //  Step, Clear and Reset the statement after each bind.
    rc = sqlite3_step( stmt );
    rc = sqlite3_clear_bindings( stmt );
    rc = sqlite3_reset( stmt );
  }
  char *zErrMsg = 0;  //  Can perhaps display the error message if rc != SQLITE_OK.
  rc = sqlite3_exec( conn, "END TRANSACTION", 0, 0, &zErrMsg );   //  End the transaction.
  if( rc!=SQLITE_OK ){
    change(PDM::Status::PDM_ERROR);
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    return 0;
  }
  rc = sqlite3_finalize( stmt );  //  Finalize the prepared statement.

  return 0;
}


