#pragma once
#include <stdlib.h>
#include <string>
class enregistrementBDD ///Cette classe permet de créer un objet qui facilite la récupération des données dans la BDD
{
public:
	
	enregistrementBDD();
	~enregistrementBDD();
	std::string nom; ///Nom à récupérer
	int score; ///Score à récupérer
};

