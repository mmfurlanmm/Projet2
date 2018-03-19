#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"

class Etoiles : public Entite
{
public:
	Etoiles(sf::Color couleur, float vitesse);
	~Etoiles();
	//sf::RectangleShape forme;
	float vitesse;

};

