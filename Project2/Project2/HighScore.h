#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "Texte.h"
#include "enregistrementBDD.h"
#include "Joueur.h"



class HighScore /// Cr�ation de la table de score
{
public:
	HighScore();
	~HighScore();
	void afficherHighScore(std::vector<enregistrementBDD*>* highScore, sf::RenderWindow &window); /// utilise les valeurs r�cup�es dans le vecteur d'enregistrementBDD et les affiche sous forme d'un tableau des scores
	std::string entrerNom(sf::RenderWindow &window); /// fonction permettant d'entrer ses initiales � la manettes ou avec les fl�ches du clavier (3 caract�res max)

	int i, j, k, lettre = 0; /// incr�menteurs permettant de parcourir les string contenant les lettres composant le nom du joueur
	float repereX = 250; /// le rep�re est un caract�re " _ " qui se d�place sous les 3 lettres composant le nom du joueur afin d'indiquer la lettre en cours de modification
	bool goX = false; /// bool�en permettant d'emp�cher un d�filement trop rapide sous les 3 lettres du nom
	bool goY = false; /// bool�en permettant d'emp�cher un d�filement trop rapide des 3 lettres du nom

};

