
/** 
@file      SQLiteManager.h
@author    Hector Martin Ruiz Rosas
@Created   01/03/2021 12:15:10 a. m.
@section   DESCRIPTION
           
*/

#ifndef __SQLITEMANAGER_H__
#define __SQLITEMANAGER_H__

#include "SQLiteMgr.h"

class SQLiteManager
{
private:
    sqlite3* DataBase;
    std::string Path;

protected:
    SQLiteMgr::Row* GetRow(sqlite3_stmt* stmt);
  
public:
    SQLiteManager(std::string _Path);
    SQLiteManager(sqlite3* db);

    virtual ~SQLiteManager(); 

    bool OpenDatabase(std::string _Path);
    bool OpenDatabase(std::string _Path, std::string User, std::string Pass);
    bool Authenticate(std::string User, std::string Pass);
    bool CreateUser(std::string User, std::string Pass, bool isAdmin = false);

    SQLiteMgr::Rows* GetRows(std::string query);

};

#endif