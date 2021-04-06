#include "SQLiteMgr.h"

namespace SQLiteMgr {

	/*SQLiteCode*/
	SQLiteMgr::SQLITECODE SQLiteCode::GetEnumValue(int CodeValue)
	{
		return static_cast<SQLiteMgr::SQLITECODE>(CodeValue);
	}

	int SQLiteCode::GetIntValue(SQLiteMgr::SQLITECODE EnumValue)
	{
		return 0;
	}


	/*SQLiteManagerException*/
	SQLiteManagerException::SQLiteManagerException(int _Code, sqlite3* _DataBase) : Code(SQLiteCode::GetEnumValue(_Code)), DataBase(_DataBase)
	{
		this->msg_ = GetError();
	}

	SQLiteManagerException::SQLiteManagerException(SQLITECODE _Code, sqlite3* _DataBase) : Code(_Code), DataBase(_DataBase)
	{
		this->msg_ = GetError();
	}

	/*
std::string SQLiteManagerException::GetError(SQLITECODE _Code)
{
	/*
	switch (_Code)
	{
	case SQLITECODE::ERROR:
		break;
	case SQLITECODE::INTERNAL:
		break;
	case SQLITECODE::PERM:
		break;
	case SQLITECODE::ABORT:
		break;
	case SQLITECODE::BUSY:
		break;
	case SQLITECODE::LOCKED:
		break;
	case SQLITECODE::NOMEM:
		break;
	case SQLITECODE::READONLY:
		break;
	case SQLITECODE::INTERRUPT:
		break;
	case SQLITECODE::IOERR:
		break;
	case SQLITECODE::CORRUPT:
		break;
	case SQLITECODE::NOTFOUND:
		break;
	case SQLITECODE::FULL:
		break;
	case SQLITECODE::CANTOPEN:
		break;
	case SQLITECODE::PROTOCOL:
		break;
	case SQLITECODE::EMPTY:
		break;
	case SQLITECODE::SCHEMA:
		break;
	case SQLITECODE::TOOBIG:
		break;
	case SQLITECODE::CONSTRAINT:
		break;
	case SQLITECODE::MISMATCH:
		break;
	case SQLITECODE::MISUSE:
		break;
	case SQLITECODE::NOLFS:
		break;
	case SQLITECODE::AUTH:
		break;
	case SQLITECODE::FORMAT:
		break;
	case SQLITECODE::RANGE:
		break;
	case SQLITECODE::NOTADB:
		break;
	case SQLITECODE::NOTICE:
		break;
	case SQLITECODE::WARNING:
		break;
	case SQLITECODE::ROW:
		break;
	case SQLITECODE::DONE:
		break;
	default:
		break;
	}* /

	return std::string();
}
*/


}