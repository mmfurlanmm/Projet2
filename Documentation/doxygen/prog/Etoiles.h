#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"

class Etoiles : public Entite /// Permet la cr�ation des �toiles pour le background
{
public:
	Etoiles(sf::Color couleur, float vitesse);
	~Etoiles();
	
	float vitesse; ///vitesse de d�placement des formes composant le fond �toil�

};

