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

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 14));
	sprite.setScale(3, 3);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height);
	//pattern = Vector2f(0.f, 5.f);
	pv = 3;
	points = 150;
	
}


Ennemi3::~Ennemi3()
{
}
