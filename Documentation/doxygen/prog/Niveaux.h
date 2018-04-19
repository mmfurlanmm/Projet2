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

class Niveaux /// Classe de cr�ation des niveaux faisant office d'�diteur de niveaux
{
public:
	


	Niveaux();
	~Niveaux();
	///C'est ici que sont cr��s les diff�rents niveaux
	void niveau1(); /// M�thode contenant toutes les donn�es du niveau 1
	void niveau2(); /// M�thode contenant toutes les donn�es du niveau 2
	void niveau3(); /// M�thode contenant toutes les donn�es du niveau 3
	void niveau4(); /// M�thode contenant toutes les donn�es du niveau 4


	void niveauTest();
	
	void gestionVecteurEnnemisEtMissilesEnnemis(); ///fonction permettant de placer les ennemis et les projectiles ennemis dans un vecteur

	///Ces bool�ens lancent une vague d'ennemi quand ils sont TRUE
	bool shoot1 = false; /// Lancement des objets ennemi1
	bool shoot12 = false; /// Lancement des objets ennemi12
	bool shoot2 = false; /// Lancement des objets ennemi2
	bool shoot3 = false; /// Lancement des objets ennemi3
	bool shootBoss = false; /// Lancement du boss 1
	bool shootBossFinal = false; /// Lancement du boss final

	

	bool fini = false;///Lorsqu'il est TRUE, le niveau est termin�. Sa valeur est test�e � la ligne 424 de la classe Game.cpp et permet de passer � l'�cran "MISSIONACCOMPLIE"
	bool finDuJeu = false; /// Lorsqu'il est TREU, permet de passer au �cran de fin du jeu
	bool go = false; ///Il arrive qu'un ennemi "bloque" l'action tant que ses PV>0. Ce bool�en permet de relancer l'action une fois les PV=0
	bool bossGo = false; /// Utilis� pour lancer l'action du boss
	bool bossPattern = false; ///quand il est TRUE, permet de lancer le pattern droite/gauche du boss 
	bool missile2Actif = true; ///Permet d'activer le deuxi�me vector de projectiles ennemis

	sf::Clock clock1; /// Clock principale des niveaux
	///Ces clocks permettent de g�rer la vitesse � laquelle les ennemis/boss sont plac� dans le vecteur d'ennemis
	sf::Clock vitesseEnnemiPop1; /// vitesse de mise en vecteur des ennemis de type 1
	sf::Clock vitesseEnnemiPop2; /// vitesse de mise en vecteur des ennemis de type 2
	sf::Clock vitesseEnnemiPop3; /// vitesse de mise en vecteur des ennemis de type 3
	sf::Clock vitesseBossPop; /// vitesse de mise en vecteur des ennemis de type boss
	///Utilis�es dans les fonctions "lancementEnnemis", permettent de g�rer � quelle vitesse les ennemis apparaissent
	unsigned int vitesseApparition1; /// vitesse d'apparition des ennemis de type 1
	unsigned int vitesseApparition12; /// vitesse d'apparition des ennemis de type 12
	unsigned int vitesseApparition2; /// vitesse d'apparition des ennemis de type 2
	unsigned int vitesseApparition3; /// vitesse d'apparition des ennemis de type 3
	unsigned int vitesseApparitionBoss = 10; /// vitesse d'apparition des ennemis de type boss

	///Fonction utilisant la vitesseApparition, permet de convertir la vitesseApparition pour faciliter la gestion par l'utilisateur
	int ennemiPop(unsigned int vitesse)
	{
		if (vitesse <= 0)
			vitesse = 1;

		return 10000 / vitesse;
	}

	
	int app = 30; /// Utilis�e uniquement dans le niveau 3 pour g�rer le nombre d'ennemi d'une vague d'ennemis
	float vit = 12; /// Utilis�e uniquement dans le niveau 3 pour g�rer la vitesse d'apparition d'une vague d'ennemis

	///////////////////////////////////////// ENNEMIS
	///Les diff�rents ennemis et leur conteneur
	Ennemi1 ennemi1; /// Ennemi de type 1
	Ennemi1 ennemi12; /// Ennemi de type 12
	Ennemi2 ennemi2; /// Ennemi de type 2
	Ennemi3 ennemi3; /// Ennemi de type 3
	EnnemiBoss ennemiBoss; /// MiniBoss du niveau 2
	EnnemiBoss ennemiBossFinal; /// Boss final

	
	std::vector<Ennemi> ennemis; /// Vector contenant les diff�rents ennemis
	

	///////////////////////////////////////// POSITION
	///Fonction g�n�rant une valeur al�atoire entre 0 et la largeur de l'�cran
	int aleatoire()
	{
		return std::rand() % int(700);
	}


	//////////////////////////////////////// PROJECTILES ENNEMIS
	///Les projectiles ennemis et leur conteneur
	MissileEnnemi missileEnnemi; /// Projectile ennemi 1
	MissileEnnemi missileEnnemi2; /// Projectile ennemi 2
	std::vector<Ennemi> vectMissileEnnemi; /// Vector contenant les projectiles ennemis
	
	float angle = 0; ///Permet de faire varier l'angle de tir des ennemis, utilis� dans la fonction tirEnSpirale
	float angle2 = 0; /// Idem qu'angle mais pour les missileEnnemi2
	
	int vitesseMissile = 0; ///Vitesse des projectiles ennemis
	int vitesseMissile2 = 0; /// Idem que vitesseMissile mais pour les missileEnnemi2

	////////////////////////////////////// JOUEUR
	Joueur joueur; /// Cr�ation d'un objet Joueur

	///////////////////////////////////// LANCEMENT DES ENNEMIS
	///Ces fonctions permettent de nettement faciliter la mani�re de lancer les ennemis, voir leur param�tres
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
	
	void rotationEnnemis() /// Cette fonction permet de g�rer l'orientation de l'ennemi dans le sens de son d�placement
	{
		for (int i = 0; i < ennemis.size(); i++)
		{
			float angle = atan2(-ennemis[i].pattern.x, ennemis[i].pattern.y) * 180 / 3.141;
			ennemis[i].sprite.setRotation(angle);
		}
	}

	///////////////////////////////////// TIR DES ENNEMIS
	///Pattern t�te chercheuse, d�place un projectile ennemi depuis la position de l'ennemi vers la position du joueur (r�cup�r�e au moment o� le projectile est tir�)
	sf::Vector2f teteChercheuse(Joueur joueur, Ennemi ennemi, float vitesse, float xRand)
	{
		sf::Vector2f aim(joueur.sprite.getPosition() - ennemi.sprite.getPosition());
		sf::Vector2f pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		pattern.x = pattern.x*vitesse + xRand;
		pattern.y = pattern.y*vitesse;
		return pattern;
	}
	///Version surcharg�e avec un argument en moins afin de l'utiliser pour d�placer un ennemi vers la position du joueur
	sf::Vector2f teteChercheuse(Joueur joueur, int pos, float vitesse)
	{
		sf::Vector2f aim(joueur.sprite.getPosition().x - pos, joueur.sprite.getPosition().y);
		sf::Vector2f pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		pattern.x = pattern.x*vitesse;
		pattern.y = pattern.y*vitesse;
		return pattern;
	}
	///Pattern de tir en forme de spirale
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
	///Pattern en spirale invers�e
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
	///L'ennemi se met � tirer � la position "d�but" et cesse � la position "fin" (en onrdonn�e)
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
	///L'ennemi se met � tirer � la position "d�but" et cesse � la position "fin" (en abscisse)
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

