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



class Game ///Cette classe g�re la logique des �vennements du jeu et l'affichage
{
public:
	Game();
	~Game();
	void logiqueDuJeu(); /// Fonction principale g�rant toute la logique et l'affichage
	

	//Niveaux
	Niveaux niveaux; /// Appel � la classe Niveaux quiposs�de toutes les m�thodes pour cr�er plus facilement des niveaux

	///Variables diverses
	float rouge = 20; /// variable utilis�e pour modifier la couleur rouge de l'arri�re plan
	float vert = 20; /// variable utilis�e pour modifier la couleur verte de l'arri�re plan
	float bleu = 20; /// variable utilis�e pour modifier la couleur bleue de l'arri�re plan

	bool goOn = false; ///goOn = false emp�che le joueur de passer � un autre �tat du jeu
	bool pause = false;//



	
	int niveauEnCours = 0; /// Variable permettant de d�lectionner le niveaux
	//Gestion du temps
	sf::Clock temps; ///horloge principale du jeu
	sf::Clock tempsTitre;///horloge utilis�e pendant l'�cran titre

	sf::Clock frame; /// pour le calcul du frame rate

	///joueur
	
	sf::Vector2f positionPrecedente; /// pour la gestion des collisions
	///armes du joueur
	sf::Clock cadenceCanon; /// clock pour g�rer la vitesse du canon
	sf::Clock tempsActivationCanon;
	sf::Clock tempsExplosion;


	sf::Clock megaBombeClock;
	sf::Clock megaBombExplosionsClock;
	bool megaBombeActive = false;
	bool megaBombeRechargee = true;
	int megaBombeCmpt = 0;

	//d�cors
	
	int etoilesSpawn = 0; /// Ces deux variables sont utilis�es pour g�rer la vitesse d'apparition des �toiles composant le fond �toil�
	int spawn1 = 35; /// Idem que etoileSpawn

	//BDD
	BDD bdd;
	std::vector<enregistrementBDD*>* vectHighScore; /// Vecteur d'objet enregistrementBDD permettant de r�cup�rer les valeurs dans la BDD

	//High Score
	HighScore highScore; /// Objet permettant d'acc�der aux fonction de cr�ation d'une table de score

	
	




};

