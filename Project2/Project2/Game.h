#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Joueur.h"
#include "Ennemi.h"
#include "Ennemi1.h"
#include "Ennemi2.h"
#include "Ennemi3.h"
#include "MissileEnnemi.h"
#include "Etoiles.h"
#include "Texte.h"
#include "Bordure.h"
#include "Missile.h"
#include "Explosion.h"
#include "Entite.h"
#include "Niveaux.h"

//Gestion des évennements du jeu

class Game
{
public:
	Game();
	~Game();
	void logiqueDuJeu();
	void affichage();

	//Niveaux
	Niveaux niveaux;

	//Variables diverses
	float rouge = 20;
	float vert = 20;
	float bleu = 20;

	bool goOn = false;//goOn = false empêche le joueur de passer à un autre état du jeu



	
	int niveauEnCours = 0;
	//Gestion du temps
	sf::Clock temps; //horloge principale du jeu
	sf::Clock tempsTitre;

	sf::Clock frame; // pour le calcul du frame rate

					 //joueur
	
	sf::Vector2f positionPrecedente; // pour la gestion des collisions
									 //armes du joueur
	sf::Clock cadenceCanon;
	sf::Clock tempsActivationCanon;
	sf::Clock tempsExplosion;


	sf::Clock megaBombeClock;
	sf::Clock megaBombExplosionsClock;
	bool megaBombeActive = false;
	bool megaBombeRechargee = true;
	int megaBombeCmpt = 0;

	//décors
	
	int etoilesSpawn = 0;
	int spawn1 = 35;
	




};

