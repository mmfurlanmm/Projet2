#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Bordure
{
public:
	Bordure(sf::Vector2f position, sf::Vector2f taille);
	~Bordure();

	void contruire(sf::RenderWindow &window); //Fonction permettant de "construire" (donc de matérialiser) les bordures invisible de l'écran
	

	sf::RectangleShape forme; //forme représentant la bordure
	sf::Vector2f taille;//taille de la bordure
	
};

