#include "Ennemi1.h"


using namespace sf;
using namespace std;





Ennemi1::Ennemi1():Ennemi()
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
	pattern = Vector2f(0.f, 15.f);
	pv = 1;
	points = 200;

	
}


Ennemi1::~Ennemi1()
{
}




