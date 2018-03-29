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

	if (clock1.getElapsedTime().asSeconds() >= 2)
	{
		shoot1 = true;
		ennemiPop1 = 100;
		ennemi1.sprite.setPosition(200, 0);
		ennemi1.pattern = Vector2f(2.5, 14);
	}


	if (clock1.getElapsedTime().asSeconds() >= 3)
	{
		shoot1 = false;
	}


	if (clock1.getElapsedTime().asSeconds() >= 4)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(500, 0);
		ennemi1.pattern = Vector2f(-2.5, 14);
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
		ennemi1.pattern = Vector2f(0, 14);
	}


	if (clock1.getElapsedTime().asSeconds() >= 6.5)
	{
		shoot1 = false;
	}


	if (clock1.getElapsedTime().asSeconds() >= 7)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(500, 0);
		ennemi1.pattern = Vector2f(0, 14);
	}

	if (clock1.getElapsedTime().asSeconds() >= 7.5)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 8)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(300, 0);
		ennemi1.pattern = Vector2f(0, 14);
	}

	if (clock1.getElapsedTime().asSeconds() >= 8.5)
	{
		shoot1 = false;
	}

	if (clock1.getElapsedTime().asSeconds() >= 9)
	{
		shoot1 = true;
		ennemi1.sprite.setPosition(400, 0);
		ennemi1.pattern = Vector2f(0, 14);
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
		ennemi1.pattern = Vector2f(0, 17);
		ennemiPop2 = 300;
		shoot2 = true;
		ennemi2.sprite.setPosition(rand() % int(700 - ennemi2.sprite.getGlobalBounds().width), 0);
		ennemi2.pattern = Vector2f(0, 5);
		ennemiPop3 = 300;
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
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (clock1.getElapsedTime().asSeconds() >= 14)
	{
		for (int i = 0; i < ennemis.size(); i++)
		{

			Vector2f aim(joueur.sprite.getPosition() - ennemis[i].sprite.getPosition());
			missileEnnemi.pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
			missileEnnemi.pattern.x = missileEnnemi.pattern.x*vitesseMissile + (rand() % (4) - 2);
			missileEnnemi.pattern.y = missileEnnemi.pattern.y*vitesseMissile;
			missileEnnemi2.pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
			missileEnnemi2.pattern.x = missileEnnemi2.pattern.x*vitesseMissile2 + (rand() % (10) - 5);
			missileEnnemi2.pattern.y = missileEnnemi2.pattern.y*vitesseMissile2;
			vitesseMissile = 15;
			vitesseMissile2 = 15;
			missileEnnemi.cercle.setRadius(15);
			ennemis[i].vitesseTir = 70;
			if (ennemis[i].sprite.getPosition().y >= 50 && ennemis[i].sprite.getPosition().y <= 150)
			{
				//if(ennemis[i].sprite.getPosition().x>=(rand()%100))
				ennemis[i].tirOk = true;
			}
			else
				ennemis[i].tirOk = false;
		}
	}
	////////////////////////////////////////////////////PATTERN ENNEMI EN CROIX
	//1
	if (clock1.getElapsedTime().asSeconds() >= 15)
	{

		shoot3 = true;
		ennemiPop3 = 500;
		ennemi3.sprite.setPosition(0, 0);
		ennemi3.pattern = Vector2f(8, 6);
	}
	if (clock1.getElapsedTime().asSeconds() >= 15.1)
	{
		shoot3 = false;
	}
//2
	if (clock1.getElapsedTime().asSeconds() >= 16.5)
	{
		shoot3 = true;
		ennemi3.sprite.setPosition(WINDOWX, 0);
		ennemi3.pattern = Vector2f(-8, 6);
	}
	if (clock1.getElapsedTime().asSeconds() >= 16.6)
	{
		shoot3 = false;
	}
	//3
	if (clock1.getElapsedTime().asSeconds() >= 18)
	{
		shoot3 = true;
		ennemi3.sprite.setPosition(0, 0);
		ennemi3.pattern = Vector2f(8, 6);
	}
	if (clock1.getElapsedTime().asSeconds() >= 18.1)
	{
		shoot3 = false;
	}
	//GROS
	if (clock1.getElapsedTime().asSeconds() >= 19.5)
	{
		shoot2 = true;
		ennemi2.sprite.setPosition(WINDOWX/2, 0);
		ennemi2.pattern = Vector2f(0, 4);
		vitesseMissile = 10;
		vitesseMissile2 = 10;
	}
	if (clock1.getElapsedTime().asSeconds() >= 19.6)
	{
		shoot2 = false;

	}
	///// FIN GROS
	//1
	
	if (clock1.getElapsedTime().asSeconds() >= 23)
	{

		shoot1 = true;
		
		ennemi1.sprite.setPosition(0, 50);
		ennemi1.pattern = Vector2f(8, 2);
	}
	if (clock1.getElapsedTime().asSeconds() >= 23.1)
	{
		shoot1 = false;
	}



	if (clock1.getElapsedTime().asSeconds() >= 26)
	{
		fini = true;
	}

	if (shoot1 == true && vitesseEnnemiPop1.getElapsedTime().asMilliseconds() > ennemiPop1)
	{
		ennemis.push_back(ennemi1);
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Niveaux::niveau2()
{

	//Pattern de tir en spirale
	missileEnnemi.pattern.x = sin(angle)*vitesseMissile;
	missileEnnemi.pattern.y = cos(angle)*vitesseMissile;
	missileEnnemi2.pattern.x = -sin(angle2)*vitesseMissile2;
	missileEnnemi2.pattern.y = -cos(angle2)*vitesseMissile2;
	//vitesse de rotation :
	angle += 3;
	angle2 += 3;
	if (angle >= 360)
		angle = 0;
	if (angle2 >= 360)
		angle2 = 0;
	//vitesse de déplacement :
	vitesseMissile = 7;
	vitesseMissile2 = 7;
	missileEnnemi.cercle.setRadius(10);
	

	if (go == false)
	{
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

		if (clock1.getElapsedTime().asSeconds() >= 19)
		{
			bossGo = true;

		}
	}


	//////////////////////////////////////////////////////////////// ENNEMI QUI TIRE
	if (bossGo == true)
	{
		shoot2 = true;
		ennemiPop2 = 3000;
		ennemi2.sprite.setPosition(350, 0);
		ennemi2.pv = 30;
		ennemi2.points = 3000;
		ennemi2.sprite.setTexture(ennemi2.texture2);
		ennemi2.sprite.setScale(6, 6);
		ennemi2.pattern = Vector2f(0, 3);

		for (int i = 0; i < ennemis.size(); i++)
		{
			shoot2 = false;
			ennemis[i].vitesseTir = 20;

			if (ennemis[i].sprite.getPosition().y >= 200)
			{
				ennemis[i].tirOk = true;
				if (bossPattern == false)//bossPattern, quand il est TRUE, permet de lancer le pattern droite/gauche du boss 
				{
					ennemis[i].pattern = Vector2f(4, 0);
					bossPattern = true;
				}
				else
				{
					if (ennemis[i].sprite.getPosition().x >= 600)
						ennemis[i].pattern = Vector2f(-4, 0);
					if (ennemis[i].sprite.getPosition().x <= 100)
						ennemis[i].pattern = Vector2f(4, 0);
				}
			}


			if (ennemis[i].inc > 36)
			{

				go = true;//Permet de passer à la suite du niveau
				bossGo = false;
				clock1.restart();
				ennemis[i].sprite.setPosition(0, 1000);
			}
		}
	}



	if (clock1.getElapsedTime().asSeconds() >= 4 && go == true)
	{


		shoot1 = true;
		ennemi1.sprite.setPosition(rand() % int(700 - ennemi1.sprite.getGlobalBounds().width), 0);
		ennemi1.pattern = Vector2f(0, 20);
		shoot2 = true;
		ennemiPop2 = 250;
		ennemi2.pv = 7;
		ennemi2.points = 500;
		ennemi2.sprite.setTexture(ennemi2.texture);
		ennemi2.sprite.setScale(4, 4);
		ennemi2.sprite.setPosition(rand() % int(700 - ennemi2.sprite.getGlobalBounds().width), 0);
		ennemi2.pattern = Vector2f(0, 5);
		shoot3 = true;

		ennemi3.sprite.setPosition(rand() % int(700 - ennemi3.sprite.getGlobalBounds().width), 0);
		ennemi3.pattern = Vector2f(0, 8);


	}

	if (go == true)
	{
		if (clock1.getElapsedTime().asSeconds() >= 5.5)
		{

			shoot2 = false;
			shoot3 = false;
		}
		if (clock1.getElapsedTime().asSeconds() >= 6.2)
		{
			shoot1 = false;

		}


		if (clock1.getElapsedTime().asSeconds() >= 11)
		{
			fini = true;
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
void Niveaux::niveauTest()
{

	for (int i = 0; i < ennemis.size(); i++)
	{

		Vector2f aim(joueur.sprite.getPosition() - ennemis[i].sprite.getPosition());
		missileEnnemi.pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		missileEnnemi.pattern.x = missileEnnemi.pattern.x*vitesseMissile + (rand() % (1) - 0.5);
		missileEnnemi.pattern.y = missileEnnemi.pattern.y*vitesseMissile;
		//missileEnnemi.pattern.y = joueur.sprite.getPosition().y;
		missileEnnemi2.pattern = (aim / sqrt(pow(aim.x, 2) + pow(aim.y, 2)));
		missileEnnemi2.pattern.x = missileEnnemi2.pattern.x*vitesseMissile2 + (rand() % (10) - 5);
		missileEnnemi2.pattern.y = missileEnnemi2.pattern.y*vitesseMissile2;
		//vitesse de rotation :
		angle += 5;
		angle2 += 5;
		if (angle >= 360)
			angle = 0;
		if (angle2 >= 360)
			angle2 = 0;
		//vitesse de déplacement :
		vitesseMissile = 15;
		vitesseMissile2 = 15;
		missileEnnemi.cercle.setRadius(15);
		//ennemis[i].vitesseTir = 200;
		//cout << "x " << missileEnnemi.pattern.x << "y " << missileEnnemi.pattern.y << endl;
	}


	if (clock1.getElapsedTime().asSeconds() >= 2)
	{
		shoot2 = true;
		ennemiPop2 = 3000;
		ennemi2.sprite.setPosition(0, 0);
		ennemi2.pv = 8;
		ennemi2.points = 2000;
		//ennemi2.sprite.setTexture(ennemi2.texture2);
		//ennemi2.sprite.setScale(6, 6);
		ennemi2.pattern = Vector2f(12, 8);
	}
	//else 

	for (int i = 0; i < ennemis.size(); i++)
	{
		//shoot2 = false;
		cout << "tirok " << ennemis[i].tirOk << endl;

		if (ennemis[i].sprite.getPosition().y >= 50 && ennemis[i].sprite.getPosition().y <= 150)
		{
			//if(ennemis[i].sprite.getPosition().x>=(rand()%100))
			ennemis[i].tirOk = true;
		}
		else
			ennemis[i].tirOk = false;

		/*if (bossPattern == false)//bossPattern, quand il est TRUE, permet de lancer le pattern droite/gauche du boss
		{
			ennemis[i].pattern = Vector2f(4, 0);
			bossPattern = true;
		}
		else
		{
			if (ennemis[i].sprite.getPosition().x >= 600)
				ennemis[i].pattern = Vector2f(-4, 0);
			if (ennemis[i].sprite.getPosition().x <= 100)
				ennemis[i].pattern = Vector2f(4, 0);
		}*/
		//}


		/*if (ennemis[i].inc > 36)
		{


			clock1.restart();
			ennemis[i].sprite.setPosition(0, 1000);
			bossPattern = false;
		}*/
	}
	//}


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
