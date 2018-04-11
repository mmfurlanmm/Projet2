#include "Ennemi.h"


using namespace sf;
using namespace std;



Ennemi::Ennemi()
{
	

}

Ennemi::~Ennemi()
{
}
void Ennemi::deplacement()
{
	
	if (move)
		sprite.move(pattern.x, pattern.y);
	
	
}

void Ennemi::explosionEnnemi()
{
	if (!explosion.loadFromFile("Images/explosion.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}
	
	sprite.setTexture(explosion);

	sprite.setTextureRect(IntRect(inc, 0, 14, 14));
	sprite.setColor(Color(0, 0, 0));
	sprite.setScale(6, 6);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height - 2);
	
	if (clockExplosion.getElapsedTime().asMilliseconds()>30)
	{
		inc+= 14;
		clockExplosion.restart();
		if (inc > 56)
		sprite.setPosition(0, 1000);
		
	}



}

void Ennemi::ennemiHit()
{
	
	if (hit == true)
	{
		sprite.setColor(Color(255, 0, 0, 190));
		if (clockHit.getElapsedTime().asSeconds() > 0.03)
		{
			hit = false;
		}



	}
	else if (hit == false)
	{
		sprite.setColor(Color(255, 255, 255, 255));
		clockHit.restart();
	}

}

void Ennemi::tirer()
{
	
	
	if (tirOk == true)
	{
		if (missileClock.getElapsedTime().asMilliseconds() > vitesseTir)
		{
			shoot = true;
			missileClock.restart();
		}
		else
		{
			shoot = false;
		}
	}
	else
		shoot = false;
	

}
