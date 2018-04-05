#include "Ennemi2.h"

using namespace sf;
using namespace std;



Ennemi2::Ennemi2() :Ennemi()
{
	if (!texture.loadFromFile("Images/ennemi3.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}

	if (!texture2.loadFromFile("Images/ennemi4.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.setScale(4, 4);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height);
//	pattern = Vector2f(0.f, 3.f);
	pv = 7;
	points = 700;
	
	
	
	
	
}




Ennemi2::~Ennemi2()
{
}
