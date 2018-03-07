#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

//#include "Ennemi1.h"

class Ennemi
{
public:
	Ennemi(sf::Vector2f pattern, int pv);
	
	
	
	~Ennemi();
	void deplacement();

	sf::Texture texture;
	sf::Sprite spriteEnnemi;
	
	sf::Vector2f pattern;
	int pv = 1;
	
	
};

