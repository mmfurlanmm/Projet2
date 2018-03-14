#include "Ennemi.h"


using namespace sf;
using namespace std;



Ennemi::Ennemi()
{
	if (!explosion.loadFromFile("Images/explosion.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}
	
}

Ennemi::~Ennemi()
{
}
void Ennemi::deplacement()
{
	//if(boom==false)
	spriteEnnemi.move(pattern);
}

void Ennemi::explosionEnnemi()
{
	

	spriteEnnemi.setTexture(explosion);
	
	spriteEnnemi.setTextureRect(IntRect(inc, 0, 14, 14));
	spriteEnnemi.setScale(6, 6);
	spriteEnnemi.setOrigin(spriteEnnemi.getTextureRect().width / 2, spriteEnnemi.getTextureRect().height-2);
	
	if (boom == true)
	{
		inc += 14;
		if (inc >56)
		{
			spriteEnnemi.setPosition(0, 1000);
		}
	}

	
		
}