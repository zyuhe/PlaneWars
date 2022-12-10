#ifndef _DBCONTROLLER_H_
#define _DBCONTROLLER_H_

#include <sqlite3.h>
#include <iostream>

using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName);
void init_db();
void updateScore(int score);
char** searchBest10();
int searchLength();


#endif