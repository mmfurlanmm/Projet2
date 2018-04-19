#include "BDD.h"
#include <stdlib.h>


using namespace std;



BDD::BDD()
{
	dbfile = "./database.db";
}


BDD::~BDD()
{
}

void BDD::openDatabase()
{
	sqlite3_initialize();
	
	sqlite3_open(dbfile.c_str(), &db);
	//cout << "bdd ouverte" << endl;
}

void BDD::closeDatabase()
{
	sqlite3_close_v2(db);
	sqlite3_shutdown();
}

bool BDD::executeQuery(std::string query)
{
	char * errmsg = 0;
	if (sqlite3_exec(db, query.c_str(), NULL, 0, &errmsg) != SQLITE_OK)
	{
		std::cout << errmsg << std::endl;
		return false;
	}
	else
	{
		return true;
	}
	
}

bool BDD::insertScore(std::string nom, int score)
{
	char cscore[10];
	
	sprintf_s(cscore, "%d", score);
	
	std::string query = "INSERT INTO scoreBDD VALUES('";
	query += nom;
	query += "',";
	query += cscore;
	query += ")";

	//std::cout << query << std::endl;

	return executeQuery(query);
	
}

std::vector<enregistrementBDD*>* BDD::getHighScore()
{
	std::string query = "SELECT nom, score FROM scorebdd ORDER BY score DESC LIMIT 6";
	std::vector<enregistrementBDD*>* highScore = new std::vector<enregistrementBDD*>;
	int i;

	sqlite3_stmt * stmt;
	sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()) + 1, &stmt, NULL);

	do {
		i = sqlite3_step(stmt);
		if (i == SQLITE_ROW)
		{
			enregistrementBDD * joueurBDD = new enregistrementBDD();
			highScore->push_back(joueurBDD);

			
			joueurBDD->nom = (char*)sqlite3_column_text(stmt, 0);
			joueurBDD->score = sqlite3_column_int(stmt, 1);
			
		}
	} while (i == SQLITE_ROW);

	return highScore;
}


