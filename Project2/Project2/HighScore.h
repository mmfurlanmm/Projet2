#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "Texte.h"
#include "enregistrementBDD.h"
#include "Joueur.h"



class HighScore /// Création de la table de score
{
public:
	HighScore();
	~HighScore();
	void afficherHighScore(std::vector<enregistrementBDD*>* highScore, sf::RenderWindow &window); /// utilise les valeurs récupées dans le vecteur d'enregistrementBDD et les affiche sous forme d'un tableau des scores
	std::string entrerNom(sf::RenderWindow &window); /// fonction permettant d'entrer ses initiales à la manettes ou avec les flèches du clavier (3 caractères max)

	int i, j, k, lettre = 0; /// incrémenteurs permettant de parcourir les string contenant les lettres composant le nom du joueur
	float repereX = 250; /// le repère est un caractère " _ " qui se déplace sous les 3 lettres composant le nom du joueur afin d'indiquer la lettre en cours de modification
	bool goX = false; /// booléen permettant d'empécher un défilement trop rapide sous les 3 lettres du nom
	bool goY = false; /// booléen permettant d'empécher un défilement trop rapide des 3 lettres du nom

};

