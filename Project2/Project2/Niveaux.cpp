#include "Niveaux.h"

using namespace sf;
using namespace std;



Niveaux::Niveaux()
{

}


Niveaux::~Niveaux()
{
}



void Niveaux::niveau1()
{
	//cout << "ennemi " << ennemis.size() << endl;
	//cout << "pos "<<ennemi1.sprite.getPosition().x << endl;
	//cout << "shoot " << shoot1 << endl;






	if (clock1.getElapsedTime().asSeconds() >= 2)
	{
		shoot1 = true;
		ennemiPop1 = 100;
		ennemi1.sprite.setPosition(200, 0);
		ennemi1.pattern = Vector2f(5, 17);
	}


	if (clock1.getElapsedTime().asSeconds() >= 3)
	{
		shoot1 = false;
	}


	if (clock1.getElapsedTime().asSeconds() >= 4)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(500, 0);
		ennemi1.pattern = Vector2f(-5, 17);
	}

	if (clock1.getElapsedTime().asSeconds() >= 5)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 6)
	{
		shoot1 = true;
		ennemiPop1 = 130;
		ennemi1.sprite.setPosition(200, 0);
		ennemi1.pattern = Vector2f(0, 17);
	}


	if (clock1.getElapsedTime().asSeconds() >= 6.5)
	{
		shoot1 = false;
	}


	if (clock1.getElapsedTime().asSeconds() >= 7)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(500, 0);
		ennemi1.pattern = Vector2f(0, 17);
	}

	if (clock1.getElapsedTime().asSeconds() >= 7.5)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 8)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(300, 0);
		ennemi1.pattern = Vector2f(0, 17);
	}

	if (clock1.getElapsedTime().asSeconds() >= 8.5)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 9)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(400, 0);
		ennemi1.pattern = Vector2f(0, 17);
	}

	if (clock1.getElapsedTime().asSeconds() >= 9.5)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 10)
	{
		shoot1 = true;
		ennemiPop1 = 100;
		ennemi1.sprite.setPosition(rand() % int(700 - ennemi1.sprite.getGlobalBounds().width), 0);
		ennemi1.pattern = Vector2f(0, 20);
		shoot2 = true;
		ennemi2.sprite.setPosition(rand() % int(700 - ennemi2.sprite.getGlobalBounds().width), 0);
		ennemi2.pattern = Vector2f(0, 5);
		shoot3 = true;
		ennemi3.sprite.setPosition(rand() % int(700 - ennemi3.sprite.getGlobalBounds().width), 0);
		ennemi3.pattern = Vector2f(0, 8);
	}
	if (clock1.getElapsedTime().asSeconds() >= 12)
	{
		shoot2 = false;
		shoot3 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 13)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 18)
	{
		fini = true;
	}

	if (shoot1 == true && vitesseEnnemiPop1.getElapsedTime().asMilliseconds() > ennemiPop1)
	{
		ennemis.push_back(ennemi1);
		vitesseEnnemiPop1.restart();
	}
	if (shoot2 == true && vitesseEnnemiPop2.getElapsedTime().asMilliseconds() > 300)
	{
		ennemis.push_back(ennemi2);
		vitesseEnnemiPop2.restart();
	}
	if (shoot3 == true && vitesseEnnemiPop3.getElapsedTime().asMilliseconds() > 200)
	{
		ennemis.push_back(ennemi3);
		vitesseEnnemiPop3.restart();
	}



	for (unsigned int i = 0; i < ennemis.size(); i++)
	{
		ennemis[i].deplacement();

		if (ennemis[i].sprite.getPosition().y > 800 + 50)
		{
			ennemis.erase(ennemis.begin() + i);
		}

	}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Niveaux::niveau2()
{
	//cout << "shoot12 " << shoot12 << endl;
	//cout << "pos "<<ennemi1.sprite.getPosition().x << endl;
	//cout << "shoot1 " << shoot1 << endl;


	if (clock1.getElapsedTime().asSeconds() >= 2 && clock1.getElapsedTime().asSeconds() < 5)
	{
		shoot3 = true;
		ennemiPop3 = 300;
		ennemi3.sprite.setPosition(350, 0);
		ennemi3.pattern = Vector2f(7, 7);
		for (int i = 0; i < ennemis.size(); i++)
		{
			if (ennemis[i].sprite.getPosition().x >= 450)
				ennemis[i].pattern = Vector2f(-7, 7);
			else if (ennemis[i].sprite.getPosition().x <= 250)
				ennemis[i].pattern = Vector2f(7, 7);
		}


	}
	if (clock1.getElapsedTime().asSeconds() >= 4)
	{
		shoot3 = false;

	}



	if (clock1.getElapsedTime().asSeconds() >= 5)
	{
		shoot1 = true;
		ennemiPop1 = 100;
		ennemi1.sprite.setPosition(150, 0);
		ennemi1.pattern = Vector2f(5, 20);

	}
	if (clock1.getElapsedTime().asSeconds() >= 6.5)
	{
		ennemi1.sprite.setPosition(550, 0);
		ennemi1.pattern = Vector2f(-5, 20);

	}
	if (clock1.getElapsedTime().asSeconds() >= 8)
	{
		shoot1 = false;

	}
	if (clock1.getElapsedTime().asSeconds() >= 9)
	{

		shoot1 = true;
		shoot12 = true;
		ennemi1.sprite.setPosition(150, 0);
		ennemi1.pattern = Vector2f(0, 20);
		ennemi12.sprite.setPosition(550, 0);
		ennemi12.pattern = Vector2f(0, 20);

	}
	if (clock1.getElapsedTime().asSeconds() >= 10)
	{
		ennemi1.pattern = Vector2f(6, 20);
		ennemi12.pattern = Vector2f(-6, 20);
	}

	if (clock1.getElapsedTime().asSeconds() >= 10.5)
	{
		ennemi1.pattern = Vector2f(0, 20);
		ennemi12.pattern = Vector2f(0, 20);
	}
	if (clock1.getElapsedTime().asSeconds() >= 11)
	{
		ennemi1.pattern = Vector2f(6, 20);
		ennemi12.pattern = Vector2f(-6, 20);
	}

	if (clock1.getElapsedTime().asSeconds() >= 11.5)
	{
		ennemi1.pattern = Vector2f(0, 20);
		ennemi12.pattern = Vector2f(0, 20);
	}

	if (clock1.getElapsedTime().asSeconds() >= 12)
	{
		ennemi1.pattern = Vector2f(5, 20);
		ennemi12.pattern = Vector2f(0, 20);
	}
	if (clock1.getElapsedTime().asSeconds() >= 12.8)
	{
		ennemi1.pattern = Vector2f(0, 20);
		ennemi12.pattern = Vector2f(0, 20);
	}

	if (clock1.getElapsedTime().asSeconds() >= 13)
	{
		ennemi1.pattern = Vector2f(0, 20);
		ennemi12.pattern = Vector2f(-5, 20);
	}

	if (clock1.getElapsedTime().asSeconds() >= 13.8)
	{
		ennemi1.pattern = Vector2f(0, 20);
		ennemi12.pattern = Vector2f(0, 20);
	}

	if (clock1.getElapsedTime().asSeconds() >= 14)
	{

		shoot12 = false;
		ennemiPop1 = 45;
		ennemi1.sprite.setPosition(rand() % int(700 - ennemi1.sprite.getGlobalBounds().width), 0);
		ennemi1.pattern = Vector2f(0, 20);
		shoot2 = true;
		ennemiPop2 = 250;
		ennemi2.sprite.setPosition(rand() % int(700 - ennemi2.sprite.getGlobalBounds().width), 0);
		ennemi2.pattern = Vector2f(0, 6);
		shoot3 = true;
		ennemiPop3 = 200;
		ennemi3.sprite.setPosition(rand() % int(700 - ennemi3.sprite.getGlobalBounds().width), 0);
		ennemi3.pattern = Vector2f(0, 8);


	}


	if (clock1.getElapsedTime().asSeconds() >= 15)
	{

		shoot2 = false;
		shoot3 = false;
	}
	if (clock1.getElapsedTime().asSeconds() >= 15.7)
	{

		shoot1 = false;

	}
	if (clock1.getElapsedTime().asSeconds() >= 17.5)
	{


		shoot1 = true;
		ennemi1.sprite.setPosition(rand() % int(700 - ennemi1.sprite.getGlobalBounds().width), 0);
		ennemi1.pattern = Vector2f(0, 20);
		shoot2 = true;
		ennemi2.sprite.setPosition(rand() % int(700 - ennemi2.sprite.getGlobalBounds().width), 0);
		ennemi2.pattern = Vector2f(0, 5);
		shoot3 = true;
		ennemi3.sprite.setPosition(rand() % int(700 - ennemi3.sprite.getGlobalBounds().width), 0);
		ennemi3.pattern = Vector2f(0, 8);


	}


	if (clock1.getElapsedTime().asSeconds() >= 18.5)
	{

		shoot2 = false;
		shoot3 = false;
	}
	if (clock1.getElapsedTime().asSeconds() >= 19.2)
	{
		shoot1 = false;

	}


	if (clock1.getElapsedTime().asSeconds() >= 22.5)
	{
		fini = true;
	}

	if (vitesseEnnemiPop1.getElapsedTime().asMilliseconds() > ennemiPop1)
	{
		if (shoot1 == true)
			ennemis.push_back(ennemi1);
		if (shoot12 == true)
			ennemis.push_back(ennemi12);

		vitesseEnnemiPop1.restart();
	}


	if (shoot2 == true && vitesseEnnemiPop2.getElapsedTime().asMilliseconds() > ennemiPop2)
	{
		ennemis.push_back(ennemi2);
		vitesseEnnemiPop2.restart();
	}
	if (shoot3 == true && vitesseEnnemiPop3.getElapsedTime().asMilliseconds() > ennemiPop3)
	{
		ennemis.push_back(ennemi3);
		vitesseEnnemiPop3.restart();
	}



	for (unsigned int i = 0; i < ennemis.size(); i++)
	{
		ennemis[i].deplacement();

		if (ennemis[i].sprite.getPosition().y > 800 + 50)
		{
			ennemis.erase(ennemis.begin() + i);
		}

	}


}
void Niveaux::niveauTest()
{
	








	if (clock1.getElapsedTime().asSeconds() >= 2)
	{
		shoot3 = true;
		ennemiPop3 = 3000;
		ennemi3.sprite.setPosition(350, 0);
		ennemi3.pattern = Vector2f(0, 5);
	}
	for (int i = 0; i < ennemis.size(); i++)
	{
		shoot3 = false;
		if (ennemis[i].sprite.getPosition().y == 200)
		{
			if (clock1.getElapsedTime().asSeconds() <= 3)
			{
				ennemis[i].pattern = Vector2f(5, 0);
			}
			if (ennemis[i].sprite.getPosition().x >= 650)
			{
				ennemis[i].pattern = Vector2f(-5, 0);
			}
			else if (ennemis[i].sprite.getPosition().x <= 50)
			{
				ennemis[i].pattern = Vector2f(5, 0);
			}
			cout << "shoot " << ennemis[i].tirOk << endl;

		}
		if (ennemis[i].pv <= 0)
		{
			clock1.restart();
		
			
		}
	}







	if (vitesseEnnemiPop1.getElapsedTime().asMilliseconds() > ennemiPop1)
	{
		if (shoot1 == true)
			ennemis.push_back(ennemi1);
		if (shoot12 == true)
			ennemis.push_back(ennemi12);

		vitesseEnnemiPop1.restart();
	}


	if (shoot2 == true && vitesseEnnemiPop2.getElapsedTime().asMilliseconds() > ennemiPop2)
	{
		ennemis.push_back(ennemi2);
		vitesseEnnemiPop2.restart();
	}
	if (shoot3 == true && vitesseEnnemiPop3.getElapsedTime().asMilliseconds() > ennemiPop3)
	{
		ennemis.push_back(ennemi3);
		vitesseEnnemiPop3.restart();
	}



	for (unsigned int i = 0; i < ennemis.size(); i++)
	{
		ennemis[i].deplacement();

		if (ennemis[i].sprite.getPosition().y > 800 + 50)
		{
			ennemis.erase(ennemis.begin() + i);
		}

	}



}
