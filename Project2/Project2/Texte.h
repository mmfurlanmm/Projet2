#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Texte
{
public:
	Texte(int tailleTexte, sf::Vector2f position, std::string textString);
	~Texte();

	sf::Text ecrireTexte();

	sf::Text text;
	sf::Font font;
	std::string textString;
	sf::Vector2f position;
	int tailleTexte;



};

