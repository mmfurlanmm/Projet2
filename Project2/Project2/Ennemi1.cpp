#include "Ennemi1.h"


using namespace sf;
using namespace std;





Ennemi1::Ennemi1(sf::Vector2f pattern):Ennemi(pattern, pv)
{
	if (!texture.loadFromFile("Images/ennemi.png"))
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


Ennemi1::~Ennemi1()
{
}




