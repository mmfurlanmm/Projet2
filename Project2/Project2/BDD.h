#pragma once
#include"sqlite3.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "enregistrementBDD.h"
class BDD
{
public:
	BDD();
	~BDD();

	void openDatabase();
	void closeDatabase();
	bool executeQuery(std::string query);
	bool insertScore(std::string nom, int score);
	std::vector<enregistrementBDD*>* getHighScore();
	//std::vector<enregistrementBDD*>* highScore;

	std::string dbfile;
	sqlite3 * db;
};

