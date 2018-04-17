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
	
	void collisionEnnemi(Ennemi ennemi); // Fonction gérant la collision avec les ennemis
	void collisionBordure(Bordure bordure); // Fonction gérant la collision avec les bords de l'écran
	void joueurRepopInvincible(sf::Clock clock); // Fonction permettant de faire réapparaitre le joueur à sa position initiale lorsqu'il est touché et de le rendre invincible pendant quelques secondes
	void joueurNormalApresInvincible(); // Le joueur redevient normal et vulnérable
	void jaugecanon(); // gestion de la jauge diminuant lors de l'utilisation du canon

	
	
	
	
	sf::Vector2f joueurPositionPrecedente; // position utilisée lors des collisions avec les bords de l'écran 
	
	

	sf::Texture texture; // texture du joueur
	sf::RectangleShape hitBoxJoueur; // forme représentant la hitbox du joueur
	sf::RectangleShape formeJaugeCanon; // forme représentant la jauge du canon
	sf::RectangleShape contourJaugeCanon; // bordure de la jauge du canon


	float vitesse; // vitesse du joueur
	int pv; // points de vie du joueur
	bool invincible; // état invincible ou non
	bool move; // le joueur peut bouger ou non
	bool tempsRestart; // lo
	bool boom;
	bool animation; // lancement de 
	bool tirOK = true; // le joueur peut tirer ou non
	bool canonActif = false;
	bool slow = false;
	bool SFX = false;
	int i = 0; // incrémenteur utilisé pour l'animation du joueur

	float valeurJaugeCanon = 100; // valeur de la jauge du canon
	

	sf::Clock clock;
	
	

	sf::Time elapsed;
	
	
	

private:
};

