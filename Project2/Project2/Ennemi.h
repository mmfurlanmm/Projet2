#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"


class Ennemi : public Entite
{
public:
	Ennemi();
	~Ennemi();
	void deplacement();
	void explosionEnnemi();
	void ennemiHit();


	void tirer();
	
	
	
	sf::Texture explosion;
	sf::Texture texture;
	//sf::Sprite sprite;
	
	sf::Vector2f pattern;
	int pv;
	int points;
	bool boom = false;
	bool incrScore = true;
	bool dégatsJoueur = true;
	bool move = true;
	bool hit = false;
	bool shoot = false;
	
	bool tirOk = false;

	

	float inc = 0;
	sf::Clock clock;
	sf::Clock clockExplosion;
	
	
	sf::Clock missileClock;
	sf::Clock missileClock2;
	int vitesseTir;



	//std::vector<Ennemi> missiles;
	

	



};

