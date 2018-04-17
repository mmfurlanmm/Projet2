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
	Explosion(int scale); //constructeur avec en param�tre l'�chelle de l'explosion (taille)
	~Explosion();
	void animation(); //fonction g�rant l'animation de l'explosion
	int inc = 0; // variable d'incr�mentation, utilis�e pour l'animation
	sf::Clock clock; // Clock utilis�e pour l'animation de l'explosion
	//sf::Clock dureeExplosion;
	
	//bool boom;
	bool trigger; // 
	
	sf::Texture textureExplosion; //texture de l'explosion
	sf::Sprite explosion; // sprite de l'explosion
};

