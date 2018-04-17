#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>

#include <string>
#include "Entite.h"
#include "Ennemi.h"
#include "Ennemi1.h"
#include "Ennemi2.h"
#include "Ennemi3.h"
#include "EnnemiBoss.h"
#include "MissileEnnemi.h"
#include "Joueur.h"

class Niveaux
{
public:
	


	Niveaux();
	~Niveaux();
	//C'est ici que sont créés les différents niveaux
	void niveau1();
	void niveau2();
	void niveau3();

	void niveauTest();
	//fonction permettant de placer les ennemis et les projectiles ennemis dans un vecteur
	void gestionVecteurEnnemisEtMissilesEnnemis();

	//Ces booléens lancent une vague d'ennemi quand ils sont TRUE
	bool shoot1 = false;
	bool shoot12 = false;
	bool shoot2 = false;
	bool shoot3 = false;
	bool shootBoss = false;

	bool fini = false;//Lorsqu'il est TRUE, le niveau est terminé. Sa valeur est testée à la ligne 424 de la classe Game.cpp et permet de passer à l'écran "MISSIONACCOMPLIE"
	bool go = false; //Il arrive qu'un ennemi "bloque" l'action tant que ses PV>0. Ce booléen permet de relancer l'action une fois les PV=0
	bool bossGo = false; // Utilisé pour lancer l'action du boss
	bool bossPattern = false; //quand il est TRUE, permet de lancer le pattern droite/gauche du boss 
	bool missile2Actif = true; //Permet d'activer le deuxième vector de projectiles ennemis

	sf::Clock clock1; // Clock principale des niveaux
	//Ces clocks permettent de gérer la vitesse à laquelle les ennemis/boss sont placé dans le vecteur d'ennemis
	sf::Clock vitesseEnnemiPop1; 
	sf::Clock vitesseEnnemiPop2;
	sf::Clock vitesseEnnemiPop3;
	sf::Clock vitesseBossPop;
	//Utilisées dans les fonctions "lancementEnnemis", permettent de gérer à quelle vitesse les ennemis apparaissent
	unsigned int vitesseApparition1;
	unsigned int vitesseApparition12;
	unsigned int vitesseApparition2;
	unsigned int vitesseApparition3;
	unsigned int vitesseApparitionBoss = 1;

	//Fonction utilisant la vitesseApparition, permet de convertir la vitesseApparition pour faciliter la gestion par l'utilisateur
	int ennemiPop(unsigned int vitesse)
	{
		if (vitesse <= 0)
			vitesse = 1;

		return 10000 / vitesse;
	}

	//sf::Clock pattern;


	///////////////////////////////////////// ENNEMIS
	//Les différents ennemis et leurs conteneurs
	Ennemi1 ennemi1;
	Ennemi1 ennemi12;
	Ennemi2 ennemi2;
	Ennemi3 ennemi3;
	EnnemiBoss ennemiBoss;
	std::vector<Ennemi> ennemis;
	std::vector<Ennemi> ennemis2;

	///////////////////////////////////////// POSITION
	//Fonction générant une valeur aléatoire entre 0 et la largeur de l'écran
	int aleatoire()
	{
		return std::rand() % int(700);
	}


	//////////////////////////////////////// PROJECTILES ENNEMIS
	//Les projectiles ennemis et leur conteneur
	MissileEnnemi missileEnnemi;
	MissileEnnemi missileEnnemi2;
	std::vector<Ennemi> vectMissileEnnemi;
	//Permet de faire varier l'angle de tir des ennemis, utilisé dans la fonction tirEnSpirale
	float angle = 0;
	float angle2 = 0;
	//Vitesse des projectiles ennemis
	int vitesseMissile = 0;
	int vitesseMissile2 = 0;

	////////////////////////////////////// JOUEUR
	Joueur joueur;

	///////////////////////////////////// LANCEMENT DES ENNEMIS
	//Ces fonctions permettent de nettement faciliter la manière de lancer les ennemis, voir leur paramètres
	void lancementEnnemis1(float debut, float fin, int vitesseApparition, int x, int y, float vitesseX, float vitesseY)
	{
		if (clock1.getElapsedTime().asSeconds() >= debut)
		{
			shoot1 = true;
			vitesseApparition1 = vitesseApparition;
			ennemi1.sprite.setPosition(x, y);
			ennemi1.pattern = sf::Vector2f(vitesseX, vitesseY);
			
		}
		if (clock1.getElapsedTime().asSeconds() >= fin)
		{
			shoot1 = false;
		}


	}
	void lancementEnnemis12(float debut, float fin, int vitesseApparition, int x, int y, float vitesseX, float vitesseY)
	{
		if (clock1.getElapsedTime().asSeconds() >= debut)
		{
			shoot12 = true;
			vitesseApparition12 = vitesseApparition;
			ennemi12.sprite.setPosition(x, y);
			ennemi12.pattern = sf::Vector2f(vitesseX, vitesseY);
			
		}
		if (clock1.getElapsedTime().asSeconds() >= fin)
		{
			shoot12 = false;
		}


	}
	void lancementEnnemis2(float debut, float fin, int vitesseApparition, int x, int y, float vitesseX, float vitesseY)
	{
		if (clock1.getElapsedTime().asSeconds() >= debut)
		{
			shoot2 = true;
			vitesseApparition2 = vitesseApparition;
			ennemi2.sprite.setPosition(x, y);
			ennemi2.pattern = sf::Vector2f(vitesseX, vitesseY);
			
		}
		if (clock1.getElapsedTime().asSeconds() >= fin)
		{
			shoot2 = false;
		}

	}
	void lancementEnnemis3(float debut, float fin, int vitesseApparition, int x, int y, float vitesseX, float vitesseY)
	{
		if (clock1.getElapsedTime().asSeconds() >= debut)
		{
			shoot3 = true;
			vitesseApparition3 = vitesseApparition;
			ennemi3.sprite.setPosition(x, y);
			ennemi3.pattern = sf::Vector2f(vitesseX, vitesseY);
			
		}
		if (clock1.getElapsedTime().asSeconds() >= fin)
		{
			shoot3 = false;
		}

	}

	///////////////////////////////////// TIR DES ENNEMIS
	//Pattern tête chercheuse, déplace un projectile ennemi depuis la position de l'ennemi vers la position du joueur (récupérée au moment où le projectile est tiré)
	sf::Vector2f teteChercheuse(Joueur joueur, Ennemi ennemi, float vitesse, float xRand)
	{
		sf::Vector2f aim(joueur.sprite.getPosition() - ennemi.sprite.getPosition());
		sf::Vector2f pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		pattern.x = pattern.x*vitesse + xRand;
		pattern.y = pattern.y*vitesse;
		return pattern;
	}
	//Version surchargée avec un argument en moins afin de l'utiliser pour déplacer un ennemi vers la position du joueur
	sf::Vector2f teteChercheuse(Joueur joueur, int pos, float vitesse)
	{
		sf::Vector2f aim(joueur.sprite.getPosition().x - pos, joueur.sprite.getPosition().y);
		sf::Vector2f pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		pattern.x = pattern.x*vitesse;
		pattern.y = pattern.y*vitesse;
		return pattern;
	}
	//Pattern de tir en forme de spirale
	sf::Vector2f spirale(float vitesseRotation, float vitesseDeplacement)
	{
		sf::Vector2f pattern;

		pattern.x = sin(angle)*vitesseDeplacement;
		pattern.y = cos(angle)*vitesseDeplacement;

		angle += vitesseRotation;

		if (angle >= 360)
			angle = 0;
		return pattern;
	}
	//Pattern en spirale inversée
	sf::Vector2f reverseSpirale(float vitesseRotation, float vitesseDeplacement)
	{
		sf::Vector2f pattern;

		pattern.x = -sin(angle2)*vitesseDeplacement;
		pattern.y = -cos(angle2)*vitesseDeplacement;

		angle2 += vitesseRotation;

		if (angle2 >= 360)
			angle2 = 0;
		return pattern;
	}
	//L'ennemi se met à tirer à la position "début" et cesse à la position "fin" (en onrdonnée)
	bool tirY(Ennemi ennemi, int debut, int fin)
	{
		bool Ok;
		if (ennemi.sprite.getPosition().y >= debut && ennemi.sprite.getPosition().y <= fin)
		{
			Ok = true;
		}
		else
			Ok = false;
		return Ok;
	}
	//L'ennemi se met à tirer à la position "début" et cesse à la position "fin" (en abscisse)
	bool tirX(Ennemi ennemi, int debut, int fin)
	{
		bool Ok;
		if (ennemi.sprite.getPosition().x >= debut && ennemi.sprite.getPosition().x <= fin)
		{
			Ok = true;
		}
		else
			Ok = false;
		return Ok;
	}

};

