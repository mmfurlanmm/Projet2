#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Entite
{
public:
	Entite();
	~Entite();

	sf::Sprite sprite;
	sf::RectangleShape forme;
};

