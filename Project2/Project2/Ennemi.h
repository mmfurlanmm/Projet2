#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>






class Ennemi
{
public:
	Ennemi();
	~Ennemi();
	void deplacement();
	void explosionEnnemi();
	
	
	
	sf::Texture explosion;
	sf::Texture texture;
	sf::Sprite spriteEnnemi;
	
	sf::Vector2f pattern;
	int pv;
	int points;
	bool boom = false;
	bool incrScore = true;
	bool d�gatsJoueur = true;
	float inc = 0;

};

