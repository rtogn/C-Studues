#include <iostream>
#include <fstream>
#include "CppSQLite3.h"
#include "RandomNumbers.h"
#include "NameFunctions.h"

CppSQLite3DB db;
const char* gszFile = "C:\\Users\\Lobster\\Desktop\\belogus.db";

cout << "SQLite Version: " << db.SQLiteVersion() << std::endl;

remove(gszFile);
db.open(gszFile);
cout << endl << "Creating stock table" << endl;
db.execDML("CREATE TABLE stocks( "
           "ID INT PRIMARY KEY AUTOINCREMENT,"
           "symbol STRING NOT NULL,"
           "name STRING,"
           "Sector STRING,"
           "Industry STRING,"
                              "  );");

int nRows = db.execDML("insert into test  values(7, 'belogus');");
cout << nRows << " rows inserted" << endl;
