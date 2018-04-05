#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"
#include "Ennemi.h"
#include "Bordure.h"


#define WINDOWX 700
#define WINDOWY 800
#define PVORIGINE 4

const sf::Vector2f POSITION_D_ORIGINE_JOUEUR(WINDOWX / 2, WINDOWY - 30);


class Joueur : public Entite
{
public:
	Joueur();
	~Joueur();

	
	sf::Vector2f deplacement();
	
	void collisionEnnemi(Ennemi ennemi);
	void collisionBordure(Bordure bordure);
	void joueurRepopInvincible(sf::Clock clock);
	void joueurNormalApresInvincible();
	void jaugecanon();

	
	
	
	
	sf::Vector2f joueurPositionPrecedente;
	
	

	sf::Texture texture;
	sf::RectangleShape hitBoxJoueur;
	sf::RectangleShape formeJaugeCanon;
	sf::RectangleShape contourJaugeCanon;


	float vitesse;
	int pv;
	bool invincible;
	bool move;
	bool tempsRestart;
	bool boom;
	bool animation;
	bool tirOK = true;
	bool canonActif = false;
	int i = 0;

	float valeurJaugeCanon = 100;
	

	sf::Clock clock;
	
	

	sf::Time elapsed;
	
	
	

private:
};

