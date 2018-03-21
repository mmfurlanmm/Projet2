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
	if(move)
	sprite.move(pattern);
}

void Ennemi::explosionEnnemi()
{
	

	sprite.setTexture(explosion);
	
	sprite.setTextureRect(IntRect(inc, 0, 14, 14));
	sprite.setScale(6, 6);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height-2);
	
	if (boom == true)
	{
		inc += 14;
		if (inc >56)
		{
			sprite.setPosition(0, 1000);
		}
	}

	
		
}

void Ennemi::ennemiHit()
{
	cout << clock.getElapsedTime().asSeconds() << endl;
	cout << hit << endl;
	if (hit == false)
		sprite.setColor(Color(255, 255, 255, 255));


	
		sprite.setColor(Color(255, 0, 0, 80));
		clock.restart();
	
	//if (clock.getElapsedTime().asSeconds() > 1)
		//hit = false;
	

	
	
	
	
}
