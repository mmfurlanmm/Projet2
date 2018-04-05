#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Entite.h"
#include "Ennemi.h"
#include "Ennemi1.h"
#include "Ennemi2.h"
#include "Ennemi3.h"
#include "MissileEnnemi.h"
#include "Joueur.h"

class Niveaux
{
public:
	Niveaux();
	~Niveaux();
	void niveau1();
	void niveau2();
	void niveau3();

	void niveauTest();
	void gestionVecteurEnnemisEtMissilesEnnemis();


	bool shoot1 = false;
	bool shoot12 = false;
	bool shoot2 = false;
	bool shoot3 = false;
	bool fini = false;
	bool go = false;
	bool bossGo = false;
	bool bossPattern = false;
	bool tirEnnemi = false;
	bool missile2Actif = false;

	sf::Clock clock1;
	
	sf::Time timeLine;
	sf::Clock clockBoss;
	sf::Clock vitesseEnnemiPop1;
	sf::Clock vitesseEnnemiPop2;
	sf::Clock vitesseEnnemiPop3;
	unsigned int vitesseApparition1;
	unsigned int vitesseApparition12;
	unsigned int vitesseApparition2;
	unsigned int vitesseApparition3;

	int ennemiPop(unsigned int vitesse)
	{
		if (vitesse <= 0)
			vitesse = 1;

		return 10000 / vitesse;
	}

	sf::Clock pattern;


	///////////////////////////////////////// ENNEMIS
	Ennemi1 ennemi1;
	Ennemi1 ennemi12;
	Ennemi2 ennemi2;
	Ennemi3 ennemi3;
	std::vector<Ennemi> ennemis;
	std::vector<Ennemi> ennemis2;

	///////////////////////////////////////// POSITION
	int aleatoire()
	{
		return std::rand() % int(700);
	}


	//////////////////////////////////////// PROJECTILES ENNEMIS
	MissileEnnemi missileEnnemi;
	MissileEnnemi missileEnnemi2;
	std::vector<Ennemi> vectMissileEnnemi;
	float angle = 0;
	int vitesseMissile = 0;
	float angle2 = 0;
	int vitesseMissile2 = 0;

	////////////////////////////////////// JOUEUR
	Joueur joueur;

	///////////////////////////////////// LANCEMENT DES ENNEMIS
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
	sf::Vector2f teteChercheuse(Joueur joueur, Ennemi ennemi, float vitesse, float xRand)
	{
		sf::Vector2f aim(joueur.sprite.getPosition() - ennemi.sprite.getPosition());
		sf::Vector2f pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		pattern.x = pattern.x*vitesse + xRand;
		pattern.y = pattern.y*vitesse;
		return pattern;
	}
	sf::Vector2f teteChercheuse(Joueur joueur, int pos, float vitesse)
	{
		sf::Vector2f aim(joueur.sprite.getPosition().x - pos, joueur.sprite.getPosition().y);
		sf::Vector2f pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		pattern.x = pattern.x*vitesse;
		pattern.y = pattern.y*vitesse;
		return pattern;
	}
	
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

