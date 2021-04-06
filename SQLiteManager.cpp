#include "SQLiteManager.h"


SQLiteManager::SQLiteManager(std::string _Path)
{

	this->OpenDatabase(_Path);

}

SQLiteManager::SQLiteManager(sqlite3* db) : DataBase(db)
{
	if (db != nullptr) 
	{
		this->Path = std::string();
	}

}

SQLiteManager::~SQLiteManager()
{
	sqlite3_close(this->DataBase);
	return;
}

bool SQLiteManager::OpenDatabase(std::string _Path)
{
	SQLiteMgr::SQLITECODE answer = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_open_v2(_Path.c_str(), &this->DataBase, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, 0));

	return (answer == SQLiteMgr::SQLITECODE::SQLOK)? true : throw SQLiteMgr::SQLiteManagerException(answer,this->DataBase);
}

bool SQLiteManager::OpenDatabase(std::string _Path, std::string User, std::string Pass)
{
	SQLiteMgr::SQLITECODE answer = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_open_v2(_Path.c_str(), &this->DataBase, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, 0));

	if(answer == SQLiteMgr::SQLITECODE::SQLOK)
		answer = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_user_authenticate(this->DataBase, User.c_str(), Pass.c_str(), Pass.size()));
	else
		throw SQLiteMgr::SQLiteManagerException(answer, this->DataBase);
		

	return (answer == SQLiteMgr::SQLITECODE::SQLOK) ? true : throw SQLiteMgr::SQLiteManagerException(answer, this->DataBase);

}

bool SQLiteManager::Authenticate(std::string User, std::string Pass)
{

	SQLiteMgr::SQLITECODE answer = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_user_authenticate(this->DataBase, User.c_str(), Pass.c_str(), Pass.size()));

	return (answer == SQLiteMgr::SQLITECODE::SQLOK) ? true : throw SQLiteMgr::SQLiteManagerException(answer, this->DataBase);

}

bool SQLiteManager::CreateUser(std::string User, std::string Pass, bool isAdmin)
{

	SQLiteMgr::SQLITECODE answer = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_user_add(this->DataBase, User.c_str(), Pass.c_str(), Pass.size(), isAdmin));

	return (answer == SQLiteMgr::SQLITECODE::SQLOK) ? true : throw SQLiteMgr::SQLiteManagerException(answer, this->DataBase);

}


SQLiteMgr::Rows* SQLiteManager::GetRows(std::string query)
{
	sqlite3_stmt* stmt;

	SQLiteMgr::Rows* QueryRows = new SQLiteMgr::Rows();

	SQLiteMgr::SQLITECODE state = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_prepare_v2(this->DataBase, query.c_str(), -1, &stmt, NULL));

	if (state != SQLiteMgr::SQLITECODE::SQLOK) throw SQLiteMgr::SQLiteManagerException(state, this->DataBase);
		
	while ((state = SQLiteMgr::SQLiteCode::GetEnumValue(sqlite3_step(stmt))) == SQLiteMgr::SQLITECODE::ROW) {
		QueryRows->push_back(GetRow(stmt));
	}

	if (state != SQLiteMgr::SQLITECODE::DONE) throw SQLiteMgr::SQLiteManagerException(state, this->DataBase);
		

	sqlite3_finalize(stmt);

	return QueryRows;
}


SQLiteMgr::Row* SQLiteManager::GetRow(sqlite3_stmt* stmt)
{

	SQLiteMgr::Row* NewRow = new SQLiteMgr::Row();

	for (int i = 0; i < sqlite3_column_count(stmt); ++i) {

		std::string key = sqlite3_column_name(stmt,i);

		switch (sqlite3_column_type(stmt, i))
		{
		case SQLiteMgr::SQLTYPE::INTEGER:
			NewRow->insert(std::pair<std::string, int>(key, sqlite3_column_int(stmt, i)));
			break;

		case SQLiteMgr::SQLTYPE::FLOAT:
			NewRow->insert(std::pair<std::string, double>(key, sqlite3_column_double(stmt, i)));
			break;

		case SQLiteMgr::SQLTYPE::TEXT:
			NewRow->insert(std::pair<std::string, std::string>(key, reinterpret_cast<const char*>(sqlite3_column_text(stmt, i))));
			break;
		
		case SQLiteMgr::SQLTYPE::BLOB:
			NewRow->insert(std::pair<std::string, int>(key, sqlite3_column_bytes(stmt, i)));
			break;

		case SQLiteMgr::SQLTYPE::SQLNULL:
			NewRow->insert(std::pair<std::string, std::string>(key, "NULL"));
			break;
		}
	}

	return new SQLiteMgr::Row();
}


