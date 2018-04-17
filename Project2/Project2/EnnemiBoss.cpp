#include "EnnemiBoss.h"
using namespace sf;
using namespace std;



EnnemiBoss::EnnemiBoss()
{
	if (!texture.loadFromFile("Images/ennemi4.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.setScale(6, 6);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height);
	pv = 30;
	points = 5000;
}


EnnemiBoss::~EnnemiBoss()
{
}
