#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
#include "BDD.h"
#include "HighScore.h"



class Game ///Cette classe gère la logique des évennements du jeu et l'affichage
{
public:
	Game();
	~Game();
	void logiqueDuJeu(); /// Fonction principale gérant toute la logique et l'affichage
	

	//Niveaux
	Niveaux niveaux; /// Appel à la classe Niveaux quipossède toutes les méthodes pour créer plus facilement des niveaux

	///Variables diverses
	float rouge = 20; /// variable utilisée pour modifier la couleur rouge de l'arrière plan
	float vert = 20; /// variable utilisée pour modifier la couleur verte de l'arrière plan
	float bleu = 20; /// variable utilisée pour modifier la couleur bleue de l'arrière plan

	bool goOn = false; ///goOn = false empêche le joueur de passer à un autre état du jeu
	bool pause = false;//



	
	int niveauEnCours = 0; /// Variable permettant de délectionner le niveaux
	//Gestion du temps
	sf::Clock temps; ///horloge principale du jeu
	sf::Clock tempsTitre;///horloge utilisée pendant l'écran titre

	sf::Clock frame; /// pour le calcul du frame rate

	///joueur
	
	sf::Vector2f positionPrecedente; /// pour la gestion des collisions
	///armes du joueur
	sf::Clock cadenceCanon; /// clock pour gérer la vitesse du canon
	sf::Clock tempsActivationCanon;
	sf::Clock tempsExplosion;


	sf::Clock megaBombeClock;
	sf::Clock megaBombExplosionsClock;
	bool megaBombeActive = false;
	bool megaBombeRechargee = true;
	int megaBombeCmpt = 0;

	//décors
	
	int etoilesSpawn = 0; /// Ces deux variables sont utilisées pour gérer la vitesse d'apparition des étoiles composant le fond étoilé
	int spawn1 = 35; /// Idem que etoileSpawn

	//BDD
	BDD bdd;
	std::vector<enregistrementBDD*>* vectHighScore; /// Vecteur d'objet enregistrementBDD permettant de récupérer les valeurs dans la BDD

	//High Score
	HighScore highScore; /// Objet permettant d'accéder aux fonction de création d'une table de score

	
	




};

