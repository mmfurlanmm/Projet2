#pragma once
#include"sqlite3.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "enregistrementBDD.h"
class BDD ///Classe g�rant la cr�ation de la BDD
{
public:
	BDD();
	~BDD();

	void openDatabase(); ///Fonction d'ouverture de la base de donn�es
	void closeDatabase(); ///Fonction de fermeture de la base de donn�es
	bool executeQuery(std::string query); 
	bool insertScore(std::string nom, int score); ///Fonction permettant d'�crire dans la BDD
	std::vector<enregistrementBDD*>* getHighScore(); /// R�cup�ration des 6 meilleurs scores
	

	std::string dbfile; ///Chemin d'acc�s de la BDD
	sqlite3 * db; ///Pointeur vers la BDD
};

