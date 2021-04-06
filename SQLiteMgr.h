#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <typeinfo>
#include <any>

#include "Sqlite/sqlite3.h"
#include "Sqlite/sqlite3userauth.h"


namespace SQLiteMgr {

    enum class SQLITECODE : int
    {
        SQLOK = SQLITE_OK,
        SQLERROR = SQLITE_ERROR,
        INTERNAL = SQLITE_INTERNAL,
        PERM = SQLITE_PERM,
        ABORT = SQLITE_ABORT,
        BUSY = SQLITE_BUSY,
        LOCKED = SQLITE_LOCKED,
        NOMEM = SQLITE_NOMEM,
        READONLY = SQLITE_READONLY,
        INTERRUPT = SQLITE_INTERRUPT,
        IOERR = SQLITE_IOERR,
        CORRUPT = SQLITE_CORRUPT,
        NOTFOUND = SQLITE_NOTFOUND,
        FULL = SQLITE_FULL,
        CANTOPEN = SQLITE_CANTOPEN,
        PROTOCOL = SQLITE_PROTOCOL,
        EMPTY = SQLITE_EMPTY,
        SCHEMA = SQLITE_SCHEMA,
        TOOBIG = SQLITE_TOOBIG,
        CONSTRAINT = SQLITE_CONSTRAINT,
        MISMATCH = SQLITE_MISMATCH,
        MISUSE = SQLITE_MISUSE,
        NOLFS = SQLITE_NOLFS,
        AUTH = SQLITE_AUTH,
        FORMAT = SQLITE_FORMAT,
        RANGE = SQLITE_RANGE,
        NOTADB = SQLITE_NOTADB,
        NOTICE = SQLITE_NOTICE,
        WARNING = SQLITE_WARNING,
        ROW = SQLITE_ROW,
        DONE = SQLITE_DONE,
    };

    enum SQLTYPE : int
    {
        INTEGER = SQLITE_INTEGER,
        FLOAT = SQLITE_FLOAT,
        TEXT = SQLITE_TEXT,
        BLOB = SQLITE_BLOB,
        SQLNULL = SQLITE_NULL
    };

    class SQLiteCode {

    public:
        static SQLiteMgr::SQLITECODE GetEnumValue(int CodeValue);
        static int GetIntValue(SQLiteMgr::SQLITECODE EnumValue);

    };

    class Row : public std::map <std::string, std::any>
    {
    private:
        int index;
    };

    class Rows : public std::list<Row*>
    {
    private:
        int index;
    };

    class SQLiteManagerException : public virtual std::exception {
    private:
        SQLiteMgr::SQLITECODE Code;
        sqlite3* DataBase;

    public:
        SQLiteManagerException(int _Code, sqlite3* _DataBase);

        SQLiteManagerException(SQLITECODE _Code, sqlite3* _DataBase);

        //static std::string GetError(SQLiteMgr::SQLITECODE _Code) /*const*/ { return std::string();  };

        std::string GetError() const { return std::string(sqlite3_errmsg(this->DataBase)); };

        virtual ~SQLiteManagerException() noexcept {}

        virtual const char* what() const noexcept {
            return msg_.c_str();
        }

    protected:
        std::string msg_;

    };

};
