#include "Ennemi3.h"

using namespace sf;
using namespace std;



Ennemi3::Ennemi3(sf::Vector2f pattern) :Ennemi(pattern, pv)
{
	if (!texture.loadFromFile("Images/ennemi2.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}

	spriteEnnemi.setTexture(texture);
	spriteEnnemi.setTextureRect(IntRect(0, 0, 16, 14));
	spriteEnnemi.setScale(3, 3);
	spriteEnnemi.setOrigin(spriteEnnemi.getTextureRect().width / 2, spriteEnnemi.getTextureRect().height);
	this->pattern = pattern;
	deplacement();
}


Ennemi3::~Ennemi3()
{
}
