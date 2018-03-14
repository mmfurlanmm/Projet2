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

	spriteEnnemi.setTexture(texture);
	spriteEnnemi.setTextureRect(IntRect(0, 0, 16, 14));
	spriteEnnemi.setScale(4, 4);
	spriteEnnemi.setOrigin(spriteEnnemi.getTextureRect().width / 2, spriteEnnemi.getTextureRect().height);
	pattern = Vector2f(0.f, 3.f);
	pv = 7;
	points = 500;
	
	
	
	
	
}




Ennemi2::~Ennemi2()
{
}
