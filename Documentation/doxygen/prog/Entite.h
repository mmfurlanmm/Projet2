#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Entite ///Cette classe est la base de la plupart des objets cr��s dans le jeu. Elle poss�de un sprite et une forme
{
public:
	
	Entite();
	~Entite();

	sf::Sprite sprite; ///Sprite de l'entit� (pour ennemis/joueur)
	sf::RectangleShape forme; ///forme rectangulaire (pour les projectiles, bordures)
	sf::CircleShape cercle; ///forme circulaire (pour les projectiles)
	
};

