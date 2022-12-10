#include "DBController.h"
#include <ctime>
#include <cstring>
#include <iostream>

int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for (i = 0; i < argc; i++){
	}
	return 0;
}

void init_db(){
	sqlite3 *db = nullptr;
	int rc = -1;
	rc = sqlite3_open("test.db", &db);
	if(rc != SQLITE_OK){
		cout << "connect to db fail." << endl;
	}else{
		cout << "connect to db successfully." << endl;
	}
	const char* create_sql = "CREATE TABLE IF NOT EXISTS local_history(" \
					"ID INTEGER PRIMARY KEY AUTOINCREMENT," \
					"update_time INTEGER NOT NULL DEFAULT 0," \
					"score INTEGER NOT NULL DEFAULT 0);";
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, create_sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK ){
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	} else {
		cout << "Table created successfully." << endl;
	}
}

void updateScore(int score) {
	sqlite3 *db = nullptr;
	int rc = -1;
	string result_sql = "insert into local_history(update_time, score)" \
						" values(" + to_string(std::time(0)) + ", " + to_string(score) + ");";
	rc = sqlite3_open("test.db", &db);
	if(rc != SQLITE_OK){
		cout << "connect to db fail." << endl;
	}else{
		cout << "connect to db successfully." << endl;
	}
	char *zErrMsg = 0;
	rc = sqlite3_exec(db, result_sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK){
		cout << "update score fail: " << zErrMsg << endl;
	}else {
		cout << "update score successfully." << endl;
	}

}

char** searchBest10() {
	sqlite3 *db = nullptr;
	int rc = sqlite3_open("test.db", &db);
	char **dbres;
	char *zErrMsg = 0;
	int nrow, ncolumn;
	string select_sql = "SELECT * from local_history order by score desc limit 10";
	rc = sqlite3_get_table(db, select_sql.c_str(), &dbres, &nrow, &ncolumn, &zErrMsg);
	if(rc == SQLITE_OK) {
	} else {
		cout << zErrMsg << endl;
	}
	return dbres;
}

int searchLength() {
	sqlite3 *db = nullptr;
	int rc = sqlite3_open("test.db", &db);
	char **dbres;
	char *zErrMsg = 0;
	int nrow, ncolumn;
	string select_sql = "SELECT * from local_history order by score desc limit 10";
	rc = sqlite3_get_table(db, select_sql.c_str(), &dbres, &nrow, &ncolumn, &zErrMsg);
	if(rc == SQLITE_OK) {
	} else {
		cout << zErrMsg << endl;
	}
	return nrow;
}
