#pragma once
#include "Ennemi.h"

class Ennemi2 :	public Ennemi
{
public:
	Ennemi2(sf::Vector2f pattern, int pv);
	
	~Ennemi2();
	int pv;
};

