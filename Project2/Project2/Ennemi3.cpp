#include "Ennemi3.h"

using namespace sf;
using namespace std;



Ennemi3::Ennemi3() :Ennemi()
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
	pattern = Vector2f(0.f, 5.f);
	pv = 4;
	points = 150;
	
}


Ennemi3::~Ennemi3()
{
}
