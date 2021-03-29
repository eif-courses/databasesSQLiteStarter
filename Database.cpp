//
// Created by Marius on 3/29/2021.
//

#include "Database.h"

sqlite3 *Database::Connect(const string &path) {
  sqlite3 *db;
  sqlite3_open(path.c_str(), &db);
  if (db == nullptr) {
    cout << "Could not open database." << endl;
    return nullptr;
  } else {
    cout << "Connected to database successfully!!!" << endl;
    return db;
  }
}

int Database::Callback(void *context, int columnCount, char **columnValues, char **columnName) {

  for (int i = 0; i < columnCount; i++) {
    cout << columnValues[i] << " ";
  }
  cout << endl;

  return 0;
}

void Database::Insert(sqlite3 *db, const Product &product) {

  sqlite3_stmt *statment;
  string sql;
  sql = "insert into PRODUCTS VALUES (?,?,?,?)";


  if (sqlite3_prepare_v2(db,
                         sql.c_str(),
                         -1,
                         &statment,
                         nullptr)
      != SQLITE_OK) {

  }
  if (sqlite3_bind_null(
      statment,
      1  // Index of wildcard
  ) != SQLITE_OK) {
    printf("\nCould not bind double.\n");
    return;
  }
  if (sqlite3_bind_text(
      statment,
      2,  // Index of wildcard
      product.GetName().c_str(), // Data as -> const * char
      product.GetName().length(), // Data length
      SQLITE_STATIC
  ) != SQLITE_OK) {
    printf("\nCould not bind double.\n");
    return;
  }
  if (sqlite3_bind_text(
      statment,
      3,  // Index of wildcard
      product.GetDescription().c_str(), // Data as -> const * char
      product.GetDescription().length(), // Data length
      SQLITE_STATIC
  ) != SQLITE_OK) {
    printf("\nCould not bind double.\n");
    return;
  }
  if (sqlite3_bind_double(
      statment,
      4,  // Index of wildcard
      product.GetPrice()
  ) != SQLITE_OK) {
    printf("\nCould not bind int.\n");
    return;
  }

  if (sqlite3_step(statment) != SQLITE_DONE) {
    printf("\nCould not step (execute) stmt.\n");
    return;
  }

  printf("\n");
  //select_stmt("select * from foo");

  sqlite3_close(db);

}

void Database::CreateTable(sqlite3 *db) {

  string sql;
  char *zErrMsg = nullptr;

  /* Open database */
  int rc = sqlite3_open("products.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return;
  } else {
    fprintf(stdout, "Opened database successfully\n");
  }

  /* Create SQL statement */
  sql = "CREATE TABLE PRODUCTS("  \
      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
      "NAME           TEXT    NOT NULL," \
      "DESCRIPTION            TEXT     NOT NULL," \
      "PRICE        REAL );";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql.c_str(), Callback, nullptr, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Table created successfully\n");
  }
  sqlite3_close(db);
}

void Database::Display(sqlite3 *db) {

  char *zErrMsg = nullptr;
  const char *data = "Callback function called";

  /* Create SQL statement */
  string sql = "SELECT * from PRODUCTS";

  /* Execute SQL statement */
  int rc = sqlite3_exec(db, sql.c_str(), Callback, (void *) data, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Operation done successfully\n");
  }
}