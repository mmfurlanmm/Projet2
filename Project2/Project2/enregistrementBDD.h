#pragma once
#include <stdlib.h>
#include <string>
class enregistrementBDD
{
public:
	//Cette classe permet de créer un objet qui facilite la récupération des données dans la BDD
	enregistrementBDD();
	~enregistrementBDD();
	std::string nom; //Nom à récupérer
	int score //Score à récupérer
};

