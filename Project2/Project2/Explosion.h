#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Joueur.h"

class Explosion
{
public:
	Explosion(int scale);
	~Explosion();
	void animation();
	int inc = 0;
	sf::Clock clock;
	
	bool boom;
	bool trigger;
	
	sf::Texture textureExplosion;
	sf::Sprite explosion;
};

