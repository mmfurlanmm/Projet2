#include "Ennemi2.h"

using namespace sf;
using namespace std;



Ennemi2::Ennemi2(sf::Vector2f pattern, int pv) :Ennemi(pattern, pv)
{
	if (!texture.loadFromFile("Images/ennemi3.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}

	spriteEnnemi.setTexture(texture);
	spriteEnnemi.setTextureRect(IntRect(0, 0, 16, 14));
	spriteEnnemi.setScale(4, 4);
	spriteEnnemi.setOrigin(spriteEnnemi.getTextureRect().width / 2, spriteEnnemi.getTextureRect().height);
	this->pattern = pattern;
	this->pv = pv;
	deplacement();
	
	
}




Ennemi2::~Ennemi2()
{
}
