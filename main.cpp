#include <iostream>
#include <fstream>
#include "CppSQLite3.h"
#include "RandomNumbers.h"
#include "NameFunctions.h"
#include "GeneralIOFunctions.h"

// LOCAL FILE TREE REFERENCE MAY CAUSE ERRORS
const char* gszFile =  "..\\FntStocks\\StockSim.db";

int main()
{
    using std:: cout;
    using std:: endl;
    CppSQLite3DB db;
    cout << "SQLite Version: " << db.SQLiteVersion() << std::endl;
    // Open database with check.
    remove(gszFile);
    db.open(gszFile);
    // Create excel table based on string (only takes const char)
    cout << endl << "Creating table" << endl;
    const char* testsq = "CREATE TABLE IF NOT EXISTS Company( "
               "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
               "symbol STRING NOT NULL,"
               "name STRING,"
               "Sector STRING,"
               "Industry STRING,"
               "UNIQUE(symbol));";
    db.execDML(testsq);

 //insert into wee (symbol, name, sector, industry) values("benui", "Cheese", "POOP", "REE");
    //int nRows = db.execDML("insert into test  values(7, 'belogus');");
    //cout << nRows << " rows inserted" << endl;

    std::ofstream myfile;

    myfile.open("test.txt");
    std::string nextSymbol;
    std::string nextSector;
    std::string command;

    for (int i = 0; i < 1000; i++){
    command = "insert or ignore into Company (symbol, name, sector, industry) values("
                     "'" + nextSymbol + "',"
                     "'Name',"
                     "'"+ nextSector + "',"
                     "'Industry');";
        nextSymbol = NASDAQ_symbol_generation::GenWeightedSymbol();
        nextSector = NASDAQ_symbol_generation::GetSector();
        //cout << nextSector;

        db.execDML(command.c_str());
        fun::funLoadingSpin(i);

    }
    myfile.close();

}



