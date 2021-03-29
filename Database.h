//
// Created by Marius on 3/29/2021.
//

#ifndef DATABASESSQLITESTARTER_DATABASE_H
#define DATABASESSQLITESTARTER_DATABASE_H
#include "db/sqlite3.h"
#include "Product.h"
#include <iostream>
#include <vector>
using namespace std;

class Database {
public:
  static sqlite3 *Connect(const string &path);
  static void CreateTable(sqlite3 *db);
  static void Insert(sqlite3 *db, const Product &product);
  static void Display(sqlite3 *db);
  static int Callback(void* context,  // user-provided object (4th param to sqlite3_exec)
                     int columnCount,      // number of columns
                     char** columnValues,  // array of column values as C-style strings
                     char** columnName);    // array of column names as C-style strings);

};


#endif //DATABASESSQLITESTARTER_DATABASE_H
