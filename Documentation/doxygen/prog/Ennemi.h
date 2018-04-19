#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"


class Ennemi : public Entite /// Classe de cr�ation des vaisseaux ennemis
{
public:
	Ennemi();
	~Ennemi();
	void deplacement(); ///m�thode g�rant le d�placement des ennemis
	void explosionEnnemi(); ///Lorsqu'un ennemi n'a plus de PV, il explose. Cette m�thode permet de modifier le sprite de l'ennemi pour le transformer en explosion
	void ennemiHit(); ///Lorsqu'un ennemi est touch� mais a toujours PV>0, il clignote bri�vement en rouge. Cette m�thode modifie la couleur du sprite de l'ennemi avec la fonction SFML .setColor()


	void tirer();
	
	
	
	sf::Texture explosion; /// Texture de l'explosion
	sf::Texture texture; /// Texture normale de l'ennemi
	
	
	sf::Vector2f pattern; /// Vecteur de flottants contenant le mouvemlent de l'ennemi
	int pv; /// Nombre de points de vie de l'ennemi
	int points; /// Points rapport�s au joueur lorsque l'ennemi est d�truit
	bool boom = false;
	bool incrScore = true;
	bool d�gatsJoueur = true; /// Lorsque ce bool�en est TRUE, l'ennemi inflige des d�gats au joueur lorsqu'il y a collision
	bool move = true; /// ce bool�en est utilis� afin de bloquer le mouvement de l'ennemi lorsque ses PV=0 afin que le sprite de son explosion ne se d�place pas
	bool hit = false;
	
	bool shoot = false; ///lorsque shoot = true, l'ennemi tire
	bool tirOk = false; /// ce bool�en est utilis� afin d'activer le tir depuis une autre classe

	bool SFX = true;

	

	float inc = 0; /// variable d'incr�mentation utilis�e dans l'animation de l'explosion, permet de passer d'une frame d'animation � une autre gr�ce � une incr�mantation de 14px
	sf::Clock clockHit; /// Permet de g�rer la dur�e de la fonction ennemiHit
	sf::Clock clockExplosion; /// Clock g�rant l'animation de l'explosion
	
	
	sf::Clock missileClock;
	int vitesseTir;



	
	

	



};

