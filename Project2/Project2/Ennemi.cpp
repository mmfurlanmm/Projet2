#include "Ennemi.h"
#include "Ennemi1.h"

using namespace sf;
using namespace std;



Ennemi::Ennemi(sf::Vector2f pattern, int pv)
{
	this->pattern = pattern;
	this->pv = pv;
	
}

Ennemi::~Ennemi()
{
}
void Ennemi::deplacement()
{
	spriteEnnemi.move(pattern);
}
