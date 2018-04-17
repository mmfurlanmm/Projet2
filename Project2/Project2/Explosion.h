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
	Explosion(int scale); //constructeur avec en paramètre l'échelle de l'explosion (taille)
	~Explosion();
	void animation(); //fonction gérant l'animation de l'explosion
	int inc = 0; // variable d'incrémentation, utilisée pour l'animation
	sf::Clock clock; // Clock utilisée pour l'animation de l'explosion
	//sf::Clock dureeExplosion;
	
	//bool boom;
	bool trigger; // 
	
	sf::Texture textureExplosion; //texture de l'explosion
	sf::Sprite explosion; // sprite de l'explosion
};

