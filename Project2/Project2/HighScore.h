#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "Texte.h"
#include "enregistrementBDD.h"
#include "Joueur.h"



class HighScore
{
public:
	HighScore();
	~HighScore();
	void afficherHighScore(std::vector<enregistrementBDD*>* highScore, sf::RenderWindow &window);
	std::string entrerNom(sf::RenderWindow &window);

	int i, j, k, lettre = 0;
	float repereX = 250;
	bool goX = false;
	bool goY = false;

};

