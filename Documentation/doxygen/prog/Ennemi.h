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


class Ennemi : public Entite /// Classe de création des vaisseaux ennemis
{
public:
	Ennemi();
	~Ennemi();
	void deplacement(); ///méthode gérant le déplacement des ennemis
	void explosionEnnemi(); ///Lorsqu'un ennemi n'a plus de PV, il explose. Cette méthode permet de modifier le sprite de l'ennemi pour le transformer en explosion
	void ennemiHit(); ///Lorsqu'un ennemi est touché mais a toujours PV>0, il clignote brièvement en rouge. Cette méthode modifie la couleur du sprite de l'ennemi avec la fonction SFML .setColor()


	void tirer();
	
	
	
	sf::Texture explosion; /// Texture de l'explosion
	sf::Texture texture; /// Texture normale de l'ennemi
	
	
	sf::Vector2f pattern; /// Vecteur de flottants contenant le mouvemlent de l'ennemi
	int pv; /// Nombre de points de vie de l'ennemi
	int points; /// Points rapportés au joueur lorsque l'ennemi est détruit
	bool boom = false;
	bool incrScore = true;
	bool dégatsJoueur = true; /// Lorsque ce booléen est TRUE, l'ennemi inflige des dégats au joueur lorsqu'il y a collision
	bool move = true; /// ce booléen est utilisé afin de bloquer le mouvement de l'ennemi lorsque ses PV=0 afin que le sprite de son explosion ne se déplace pas
	bool hit = false;
	
	bool shoot = false; ///lorsque shoot = true, l'ennemi tire
	bool tirOk = false; /// ce booléen est utilisé afin d'activer le tir depuis une autre classe

	bool SFX = true;

	

	float inc = 0; /// variable d'incrémentation utilisée dans l'animation de l'explosion, permet de passer d'une frame d'animation à une autre grâce à une incrémantation de 14px
	sf::Clock clockHit; /// Permet de gérer la durée de la fonction ennemiHit
	sf::Clock clockExplosion; /// Clock gérant l'animation de l'explosion
	
	
	sf::Clock missileClock;
	int vitesseTir;



	
	

	



};

