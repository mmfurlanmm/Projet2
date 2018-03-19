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
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 14));
	sprite.setScale(3, 3);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height);
	pattern = Vector2f(0.f, 15.f);
	pv = 1;
	points = 200;

	
}


Ennemi1::~Ennemi1()
{
}




