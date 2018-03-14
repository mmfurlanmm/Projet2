#include "Explosion.h"

using namespace sf;
using namespace std;



Explosion::Explosion(int scale)
{
	
	
	if (!textureExplosion.loadFromFile("Images/explosion.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}

	explosion.setTexture(textureExplosion);
	explosion.setTextureRect(IntRect(inc, 0, 14, 14));
	explosion.setScale(scale, scale);
	explosion.setOrigin(explosion.getTextureRect().width / 2, explosion.getTextureRect().height);

	
	
}


Explosion::~Explosion()
{
}

void Explosion::animation()
{
	if (trigger == false)
		inc = 0;
	
	if (boom == true)
	{
		inc += 14;
		if (inc > 80)
			inc = 0;
	}
	
	explosion.setTextureRect(IntRect(inc, 0, 14, 14));

}
