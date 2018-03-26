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
	if (move)
		sprite.move(pattern);
}

void Ennemi::explosionEnnemi()
{


	sprite.setTexture(explosion);

	sprite.setTextureRect(IntRect(inc, 0, 14, 14));
	sprite.setScale(6, 6);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height - 2);

	if (boom == true)
	{
		inc += 14;
		if (inc > 56)
		{
			sprite.setPosition(0, 1000);
		}
	}



}

void Ennemi::ennemiHit()
{
	//cout << "hit " << hit << endl;
	//cout << "clock ennemi" << clock.getElapsedTime().asSeconds() << endl;



	if (hit == true)
	{
		sprite.setColor(Color(255, 0, 0, 190));
		if (clock.getElapsedTime().asSeconds() > 0.03)
		{
			hit = false;
		}



	}
	else if (hit == false)
	{
		sprite.setColor(Color(255, 255, 255, 255));
		clock.restart();
	}

}

void Ennemi::tirer(Ennemi missile, Ennemi missile2)
{
	

	if (/*Keyboard::isKeyPressed(Keyboard::A) &&*/ missileClock.getElapsedTime().asMilliseconds()>30)
	{

		tirOk = true;
		missileClock.restart();
		
		

	}
	else 
	{
		tirOk = false;
		
	}


	if (tirOk == true)
	{
		missile.forme.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y - sprite.getTextureRect().height));
		missiles.push_back(missile);
		missile2.forme.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y - sprite.getTextureRect().height));
		missiles.push_back(missile2);
	
	}
	


	cout << "missile" << missiles.size() << endl;




	for (unsigned int i = 0; i < missiles.size(); i++)
	{
		missiles[i].forme.move(missiles[i].pattern.x, missiles[i].pattern.y);


		if (missiles[i].forme.getPosition().y > 810 || missiles[i].forme.getPosition().y < -10 || missiles[i].forme.getPosition().x > 800 || missiles[i].forme.getPosition().x < -10)
		{
			missiles.erase(missiles.begin() + i);
		}
	}
	
	



}
