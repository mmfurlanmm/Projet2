#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Ennemi.h"
#include "Ennemi1.h"
#include "Ennemi2.h"
#include "Ennemi3.h"

class Niveaux
{
public:
	Niveaux();
	~Niveaux();
	void niveau1();
	void niveau2();
	void niveauTest();


	bool shoot1=false;
	bool shoot12 = false;
	bool shoot2=false;
	bool shoot3=false;
	bool fini = false;
	bool go = true;
	
	sf::Clock clock1;
	sf::Clock vitesseEnnemiPop1;
	sf::Clock vitesseEnnemiPop2;
	sf::Clock vitesseEnnemiPop3;
	int ennemiPop1;
	int ennemiPop2;
	int ennemiPop3;

	sf::Clock pattern;
	
	Ennemi1 ennemi1;
	Ennemi1 ennemi12;

	Ennemi2 ennemi2;
	Ennemi3 ennemi3;
	std::vector<Ennemi> ennemis;
	std::vector<Ennemi> ennemis2;

	



};

