#include "Bordure.h"
using namespace sf;
using namespace std;



Bordure::Bordure(Vector2f position, Vector2f taille)
{
	
	this->taille = taille;
	forme.setFillColor(Color::Transparent);
	forme.setPosition(position);
	forme.setSize(taille);
	
}


Bordure::~Bordure()
{
}

void Bordure::contruire(sf::RenderWindow &window)
{
	window.draw(forme);
}



