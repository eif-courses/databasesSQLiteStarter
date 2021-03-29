cmake_minimum_required(VERSION 3.17)
project(databasesSQLiteStarter)

set(CMAKE_CXX_STANDARD 14)

add_executable(databasesSQLiteStarter main.cpp db/sqlite3.c db/sqlite3.h db/sqlite3ext.h Product.cpp Product.h Database.cpp Database.h)