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


class Joueur : public Entite /// Classe de cr�ation du joueur
{
public:
	Joueur();
	~Joueur();

	
	sf::Vector2f deplacement();
	
	void collisionEnnemi(Ennemi ennemi); /// Fonction g�rant la collision avec les ennemis
	void collisionBordure(Bordure bordure); /// Fonction g�rant la collision avec les bords de l'�cran
	void joueurRepopInvincible(sf::Clock clock); /// Fonction permettant de faire r�apparaitre le joueur � sa position initiale lorsqu'il est touch� et de le rendre invincible pendant quelques secondes
	void joueurNormalApresInvincible(); /// Le joueur redevient normal et vuln�rable
	void jaugecanon(); /// gestion de la jauge diminuant lors de l'utilisation du canon

	
	
	
	
	sf::Vector2f joueurPositionPrecedente; /// position utilis�e lors des collisions avec les bords de l'�cran 
	
	

	sf::Texture texture; /// texture du joueur
	sf::RectangleShape hitBoxJoueur; /// forme repr�sentant la hitbox du joueur
	sf::RectangleShape formeJaugeCanon; /// forme repr�sentant la jauge du canon
	sf::RectangleShape contourJaugeCanon; /// bordure de la jauge du canon


	float vitesse; /// vitesse du joueur
	int pv; /// points de vie du joueur
	bool invincible; /// �tat invincible ou non
	bool move; /// le joueur peut bouger ou non
	bool tempsRestart; 
	bool boom;
	bool tirOK = true; /// le joueur peut tirer ou non
	bool canonActif = false; /// permet de v�rifier si la touche d'activation du canon est enfonc�e ou pas
	bool SFX = false; /// activation des effets sonores
	int i = 0; /// incr�menteur utilis� pour l'animation du joueur

	float valeurJaugeCanon = 100; /// valeur de la jauge du canon
	

	sf::Clock clock; /// Clock g�rant l'animation du r�acteur du vaisseau du joueur
	
private:
};

