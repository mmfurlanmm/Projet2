#pragma once
#include <stdlib.h>
#include <string>
class enregistrementBDD
{
public:
	//Cette classe permet de cr�er un objet qui facilite la r�cup�ration des donn�es dans la BDD
	enregistrementBDD();
	~enregistrementBDD();
	std::string nom; //Nom � r�cup�rer
	int score //Score � r�cup�rer
};

