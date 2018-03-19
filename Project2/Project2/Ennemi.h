#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"






class Ennemi : public Entite
{
public:
	Ennemi();
	~Ennemi();
	void deplacement();
	void explosionEnnemi();
	
	
	
	sf::Texture explosion;
	sf::Texture texture;
	//sf::Sprite sprite;
	
	sf::Vector2f pattern;
	int pv;
	int points;
	bool boom = false;
	bool incrScore = true;
	bool dégatsJoueur = true;
	bool move = true;
	float inc = 0;

};

