#include <iostream>
#include "Database.h"

int main() {

  sqlite3 *db = Database::Connect("products.db");

  //Database::CreateTable(db); // if exists comment this line
  Product product("Bread", "Black bread", 2.52);
  //Database::Insert(db, product); // Insert product

  Database::Display(db);

  return 0;
}
