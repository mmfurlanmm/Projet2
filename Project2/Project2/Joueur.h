#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

#include "Ennemi.h"
#include "Bordure.h"




class Joueur
{
public:
	Joueur();
	~Joueur();

	
	sf::Vector2f deplacement();
	void collisionEnnemi(Ennemi ennemi);
	void collisionBordure(Bordure bordure);
	

	
	bool tirOK = true;

	sf::Vector2f joueurPositionPrecedente;

	sf::Texture texture;
	sf::Sprite spriteJoueur;
	sf::RectangleShape hitBoxJoueur;
	float vitesse;
	int pv;
	bool invincible;
	bool move;
	bool tempsRestart;
	bool boom;
	
	
	

private:
};

