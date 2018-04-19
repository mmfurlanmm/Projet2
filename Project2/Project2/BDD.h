#pragma once
#include"sqlite3.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "enregistrementBDD.h"
class BDD ///Classe gérant la création de la BDD
{
public:
	BDD();
	~BDD();

	void openDatabase(); ///Fonction d'ouverture de la base de données
	void closeDatabase(); ///Fonction de fermeture de la base de données
	bool executeQuery(std::string query); 
	bool insertScore(std::string nom, int score); ///Fonction permettant d'écrire dans la BDD
	std::vector<enregistrementBDD*>* getHighScore(); /// Récupération des 6 meilleurs scores
	

	std::string dbfile; ///Chemin d'accès de la BDD
	sqlite3 * db; ///Pointeur vers la BDD
};

