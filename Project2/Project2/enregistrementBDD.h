#pragma once
#include <stdlib.h>
#include <string>
class enregistrementBDD ///Cette classe permet de cr�er un objet qui facilite la r�cup�ration des donn�es dans la BDD
{
public:
	
	enregistrementBDD();
	~enregistrementBDD();
	std::string nom; ///Nom � r�cup�rer
	int score; ///Score � r�cup�rer
};

