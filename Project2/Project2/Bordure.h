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

	void contruire(sf::RenderWindow &window); //Fonction permettant de "construire" (donc de mat�rialiser) les bordures invisible de l'�cran
	

	sf::RectangleShape forme; //forme repr�sentant la bordure
	sf::Vector2f taille;//taille de la bordure
	
};

