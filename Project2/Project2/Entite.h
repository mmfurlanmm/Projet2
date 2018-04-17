#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Entite
{
public:
	//Cette classe est la base de la plupart des objets créés dans le jeu. Elle possède un sprite et une forme
	Entite();
	~Entite();

	sf::Sprite sprite; //Sprite de l'entité (pour ennemis/joueur)
	sf::RectangleShape forme; //forme rectangulaire (pour les projectiles, bordures)
	sf::CircleShape cercle; //forme circulaire (pour les projectiles)
	
};

