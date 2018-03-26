#pragma once
#include "Ennemi.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>


class MissileEnnemi :
	public Ennemi
{
public:
	MissileEnnemi();
	~MissileEnnemi();
	sf::Vector2f patternMissile;


	
};

