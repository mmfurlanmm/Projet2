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

	gestionVecteurEnnemisEtMissilesEnnemis();
	rotationEnnemis();

	lancementEnnemis1(2, 3, 80, 200, 0, 2.5, 14);
	lancementEnnemis1(4, 5, 80, 500, 0, -2.5, 14);

	lancementEnnemis1(6, 6.6, 80, 200, 0, 0, 14);
	lancementEnnemis1(7, 7.6, 80, 500, 0, 0, 14);
	lancementEnnemis1(8, 8.6, 80, 300, 0, 0, 14);
	lancementEnnemis1(9, 9.6, 80, 400, 0, 0, 14);


	/////////////////ALEATOIRE
	lancementEnnemis1(10, 13, 80, aleatoire(), 0, 0, 17);
	lancementEnnemis2(10, 12, 20, aleatoire(), 0, 0, 5);
	lancementEnnemis3(10, 12, 40, aleatoire(), 0, 0, 8);

	//////////////////////////////////////////////////PATTERN DE MISSILLE A TETE CHERCHEUSE
	if (clock1.getElapsedTime().asSeconds() >= 14)
	{
		for (int i = 0; i < ennemis.size(); i++)
		{
			missileEnnemi.pattern = teteChercheuse(joueur, ennemis[i], 15, (rand() % (4) - 2));
			missileEnnemi2.pattern = teteChercheuse(joueur, ennemis[i], 15, (rand() % (10) - 5));
			missileEnnemi.cercle.setRadius(15);
			ennemis[i].tirOk = tirY(ennemis[i], 50, 150);
			ennemis[i].vitesseTir = 50;
		}
	}


	////////////////////////////////////////////////////PATTERN ENNEMI EN CROIX

	lancementEnnemis3(15, 15.1, 20, 0, 0, 8, 6);
	lancementEnnemis3(16.5, 16.6, 20, WINDOWX, 0, -8, 6);
	lancementEnnemis3(18, 18.1, 20, 0, 0, 8, 6);
	//GROS

	lancementEnnemis2(19.5, 19.6, 20, WINDOWX / 2, 0, 0, 4);
	///// FIN GROS

	lancementEnnemis1(23, 23.5, 20, 0, 40, 8, 2.5);

	if (clock1.getElapsedTime().asSeconds() >= 27)
		fini = true;


	

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Niveaux::niveau2()
{
	gestionVecteurEnnemisEtMissilesEnnemis();
	if (clock1.getElapsedTime().asSeconds() <= 19)
	{
		rotationEnnemis();
	}


	if (go == false)
	{
		if (clock1.getElapsedTime().asSeconds() >= 2 && clock1.getElapsedTime().asSeconds() < 5)
		{
			lancementEnnemis3(2, 4, 30, 350, 0, 7, 7);
			for (int i = 0; i < ennemis.size(); i++)
			{
				if (ennemis[i].sprite.getPosition().x >= 450)
					ennemis[i].pattern = Vector2f(-7, 7);
				else if (ennemis[i].sprite.getPosition().x <= 250)
					ennemis[i].pattern = Vector2f(7, 7);
			}
		}
		lancementEnnemis1(5, 8, 100, 150, 0, 5, 18);
		lancementEnnemis1(6.5, 8, 100, 550, 0, -5, 18);
		lancementEnnemis1(9, 15.7, 100, 150, 0, 0, 18);
		lancementEnnemis12(9, 14, 100, 550, 0, 0, 18);
		lancementEnnemis1(10, 15.7, 100, 150, 0, 6, 18);
		lancementEnnemis12(10, 14, 100, 550, 0, -6, 18);
		lancementEnnemis1(10.5, 15.7, 100, 150, 0, 0, 18);
		lancementEnnemis12(10.5, 14, 100, 550, 0, 0, 18);
		lancementEnnemis1(11, 15.7, 100, 150, 0, 6, 18);
		lancementEnnemis12(11, 14, 100, 550, 0, -6, 18);
		lancementEnnemis1(11.5, 15.7, 100, 150, 0, 0, 18);
		lancementEnnemis12(11.5, 14, 100, 550, 0, 0, 18);
		lancementEnnemis1(12, 15.7, 100, 150, 0, 5, 18);
		lancementEnnemis12(12.5, 14, 100, 550, 0, 0, 18);
		lancementEnnemis1(12.8, 15.7, 100, 150, 0, 0, 18);
		lancementEnnemis12(12.8, 14, 100, 550, 0, 0, 18);
		lancementEnnemis1(13, 15.7, 100, 150, 0, 0, 18);
		lancementEnnemis12(13, 14, 100, 550, 0, -5, 18);
		lancementEnnemis1(13.8, 15.7, 100, 150, 0, 0, 18);
		lancementEnnemis12(13.8, 14, 100, 550, 0, 0, 18);
		lancementEnnemis1(14, 15.7, 100, aleatoire(), 0, 0, 18);
		lancementEnnemis2(14, 15, 30, aleatoire(), 0, 0, 6);
		lancementEnnemis3(14, 15, 50, aleatoire(), 0, 0, 8);

		if (clock1.getElapsedTime().asSeconds() >= 19)
		{
			bossGo = true;

		}
	}
	//Pattern de tir en spirale
	missileEnnemi.pattern = spirale(4, 5);
	missileEnnemi2.pattern = reverseSpirale(4, 4);

	//////////////////////////////////////////////////////////////// ENNEMI QUI TIRE
	if (bossGo == true)
	{
		
		shootBoss = true;
		ennemiBoss.sprite.setPosition(350, 0);
		ennemiBoss.pattern = Vector2f(0, 3);
		ennemiBoss.vitesseTir = 30;
		missileEnnemi.cercle.setRadius(15);




		for (int i = 0; i < ennemis.size(); i++)
		{
			if (ennemis.size() >= 1)

				shootBoss = false;

			if (ennemis[i].sprite.getPosition().y >= 200)
			{
				ennemis[i].tirOk = true;
				if (bossPattern == false)//bossPattern, quand il est TRUE, permet de lancer le pattern droite/gauche du boss 
				{
					ennemis[i].pattern = Vector2f(3, 0);
					bossPattern = true;
				}
				else
				{
					if (ennemis[i].sprite.getPosition().x >= 600)
						ennemis[i].pattern = Vector2f(-3, 0);
					if (ennemis[i].sprite.getPosition().x <= 100)
						ennemis[i].pattern = Vector2f(3, 0);
				}
			}


			if (ennemis[i].pv <= 0)
			{

				go = true;//Permet de passer à la suite du niveau
				bossGo = false;
				bossPattern = false;
				clock1.restart();

			}
		}
	}



	if (clock1.getElapsedTime().asSeconds() >= 4 && go == true)
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

	


}

//float timeBossFloat = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Niveaux::niveau3()
{

	gestionVecteurEnnemisEtMissilesEnnemis();
	if (go == false)
	{
		missile2Actif = false;
		rotationEnnemis();
		if (clock1.getElapsedTime().asSeconds() < 12)
		{
			for (int i = 0; i < ennemis.size(); i++)
			{
				missileEnnemi.pattern = teteChercheuse(joueur, ennemis[i], 15, 0);
				missileEnnemi.cercle.setRadius(15);
				ennemis[i].vitesseTir = 1500;
				ennemis[i].tirOk = tirX(ennemis[i], 210, 500);


			}
		}

		lancementEnnemis1(3, 4.3, 20, 0, 0, 7, 5);
		lancementEnnemis1(5, 6.3, 20, WINDOWX, 0, -7, 5);
		lancementEnnemis1(7, 8.3, 20, 0, 0, 7, 5);
		lancementEnnemis1(9, 10.3, 20, WINDOWX, 0, -7, 5);

		int al = rand() % (450 - 250 + 1) + 250;
		if (clock1.getElapsedTime().asSeconds() >= 16.2 && clock1.getElapsedTime().asSeconds() <= 17.3)
		{
			app++;
			vit += 0.1;
		}
		lancementEnnemis1(12, 18, app, al, 0, teteChercheuse(joueur, al, vit).x, teteChercheuse(joueur, al, vit).y);


		if (clock1.getElapsedTime().asSeconds() >= 18 && clock1.getElapsedTime().asSeconds() < 25.4)
		{
			missile2Actif = true;
			for (int i = 0; i < ennemis.size(); i++)
			{
				ennemi2.tirOk = true;
				missileEnnemi2.pattern = spirale(7, 10);
				missileEnnemi.pattern = reverseSpirale(7, 10);

				ennemis[i].vitesseTir = 50;

			}
		}
		lancementEnnemis2(20, 21, 10, WINDOWX / 2, 0, 0, 2.5);
		lancementEnnemis3(20.5, 23, 20, joueur.sprite.getPosition().x + rand() % 20 - 10, 0, 0, 15);

		if (clock1.getElapsedTime().asSeconds() >= 25.5)
		{
			ennemi3.tirOk = true;

			for (int i = 0; i < ennemis.size(); i++)
			{
				missile2Actif = false;

				missileEnnemi.pattern = teteChercheuse(joueur, ennemis[i], 15, (rand() % (4) - 2));
				ennemis[i].vitesseTir = 200;

			}
		}
		lancementEnnemis1(27, 34, 30, joueur.sprite.getPosition().x + rand() % 20 - 10, 0, 0, 18);

		lancementEnnemis3(26, 27, 10, 0, 0, 7, 5);
		lancementEnnemis3(28, 29, 10, WINDOWX, 0, -7, 5);
		lancementEnnemis3(30, 31, 10, 0, 0, 7, 5);
		lancementEnnemis3(32, 33, 10, WINDOWX, 0, -7, 5);

		if (clock1.getElapsedTime().asSeconds() >= 35)
		{
			missile2Actif = true;
			for (int i = 0; i < ennemis.size(); i++)
			{
				ennemi2.tirOk = true;
				missileEnnemi2.pattern = spirale(7, 5);
				missileEnnemi.pattern = reverseSpirale(7, 7);

				ennemis[i].vitesseTir = 50;
				if (ennemis[i].sprite.getPosition().y > 80)
					ennemis[i].pattern.y -= 0.1;
				if (ennemis[i].pattern.y <= 0)
					ennemis[i].pattern.y = 0;


			}

		}

		lancementEnnemis2(35, 35.4, 10, 500, 0, 0, 6);
		lancementEnnemis2(38, 38.5, 10, 200, 0, 0, 6.5);

		lancementEnnemis2(42, 42.5, 10, WINDOWX / 2, 0, 0, 7);
		if (clock1.getElapsedTime().asSeconds() > 44 && ennemis.size() == 0)
		{
			go = true;
			clock1.restart();
		}
	}
	if (go == true && clock1.getElapsedTime().asSeconds() > 5)
	{
		go = false;
		fini = true;
	}

	


}
//int vit = 1;
void Niveaux::niveau4()
{
	gestionVecteurEnnemisEtMissilesEnnemis();
	ennemiBossFinal.sprite.setTexture(ennemiBoss.texture2);
	ennemiBossFinal.sprite.setTextureRect(IntRect(0, 0, 25, 50));
	ennemiBossFinal.sprite.setOrigin(ennemiBoss.sprite.getTextureRect().width / 2, 40);
	ennemiBossFinal.sprite.setScale(6, 6);
	ennemiBossFinal.pv = 150;
	ennemiBossFinal.sprite.setPosition(350, -50);
	ennemiBossFinal.pattern = Vector2f(0, 3);
	ennemiBossFinal.vitesseTir = 16;
	missile2Actif = true;
	missileEnnemi2.pattern = spirale(6, 3);
	missileEnnemi.pattern = reverseSpirale(7, 3);

	if (clock1.getElapsedTime().asSeconds() > 4 && go == false)
		shootBossFinal = true;

	for (int i = 0; i < ennemis.size(); i++)
	{


		if (ennemis.size() >= 1)
			shootBossFinal = false;

		if (ennemis[i].sprite.getPosition().y >= 300)
		{
			ennemis[i].tirOk = true;
			if (bossPattern == false)//bossPattern, quand il est TRUE, permet de lancer le pattern droite/gauche du boss 
			{
				ennemis[i].pattern = Vector2f(2, 0);
				bossPattern = true;
			}
			else
			{
				if (ennemis[i].sprite.getPosition().x >= 600)
					ennemis[i].pattern = Vector2f(-2, 0);
				if (ennemis[i].sprite.getPosition().x <= 100)
					ennemis[i].pattern = Vector2f(2, 0);
			}
		}
		if (ennemis[i].pv <= 0)
		{
			clock1.restart();
			go = true;
		}

	}
	if (clock1.getElapsedTime().asSeconds() > 5 && go == true)
	{
		go = false;
		fini = true;
		//finDuJeu = true;
	}

	

}

void Niveaux::niveauTest()
{


	int al = aleatoire();
	lancementEnnemis1(0, 150, 6, al, 0, teteChercheuse(joueur, al, 10).x, teteChercheuse(joueur, al, 10).y);

	int al2 = aleatoire();

	missile2Actif = true;
	missileEnnemi2.pattern = spirale(4, 1);
	missileEnnemi.pattern = reverseSpirale(5, 1);


	for (int i = 0; i < ennemis.size(); i++)
	{


		if (ennemis[i].sprite.getPosition().y > 400)
			ennemis[i].pattern.y = 0;
		else if (ennemis[i].sprite.getPosition().y < 100)
			ennemis[i].pattern.y = 5;
		ennemis[i].vitesseTir = 2;



	}
	lancementEnnemis1(0, 1, 10, 350, 10, 0, 5);
	ennemi1.tirOk = true;







	gestionVecteurEnnemisEtMissilesEnnemis();



}

void Niveaux::gestionVecteurEnnemisEtMissilesEnnemis()
{


	if (vitesseEnnemiPop1.getElapsedTime().asMilliseconds() > ennemiPop(vitesseApparition1))
	{
		if (shoot1 == true)
			ennemis.push_back(ennemi1);
		if (shoot12 == true)
			ennemis.push_back(ennemi12);

		vitesseEnnemiPop1.restart();
	}



	if (shoot2 == true && vitesseEnnemiPop2.getElapsedTime().asMilliseconds() > ennemiPop(vitesseApparition2))
	{
		ennemis.push_back(ennemi2);
		vitesseEnnemiPop2.restart();
	}
	if (shoot3 == true && vitesseEnnemiPop3.getElapsedTime().asMilliseconds() > ennemiPop(vitesseApparition3))
	{
		ennemis.push_back(ennemi3);
		vitesseEnnemiPop3.restart();
	}
	if (vitesseBossPop.getElapsedTime().asMilliseconds() > ennemiPop(vitesseApparitionBoss))
	{
		if (shootBoss == true)
			ennemis.push_back(ennemiBoss);
		if (shootBossFinal == true)
			ennemis.push_back(ennemiBossFinal);
		vitesseBossPop.restart();
	}

	for (unsigned int i = 0; i < ennemis.size(); i++)
	{
		ennemis[i].deplacement();

		if (ennemis[i].sprite.getPosition().y > WINDOWY + 50 || ennemis[i].sprite.getPosition().x > WINDOWX + 50 ||
			ennemis[i].sprite.getPosition().x < -50 || ennemis[i].sprite.getPosition().y < -50)
		{
			ennemis.erase(ennemis.begin() + i);
		}
	}
	for (unsigned int i = 0; i < ennemis.size(); i++)
	{
		ennemis[i].tirer();
		if (ennemis[i].shoot == true && vectMissileEnnemi.size() < 500)
		{

			missileEnnemi.cercle.setPosition(Vector2f(ennemis[i].sprite.getPosition().x, ennemis[i].sprite.getPosition().y - ennemis[i].sprite.getTextureRect().height));
			vectMissileEnnemi.push_back(missileEnnemi);
			missileEnnemi2.cercle.setPosition(Vector2f(ennemis[i].sprite.getPosition().x, ennemis[i].sprite.getPosition().y - ennemis[i].sprite.getTextureRect().height));
			if (missile2Actif == true)
				vectMissileEnnemi.push_back(missileEnnemi2);

		}

	}
	for (unsigned int i = 0; i < vectMissileEnnemi.size(); i++)
	{
		vectMissileEnnemi[i].cercle.move(vectMissileEnnemi[i].pattern.x, vectMissileEnnemi[i].pattern.y);


		if (vectMissileEnnemi[i].cercle.getPosition().y > WINDOWY + 15 || vectMissileEnnemi[i].cercle.getPosition().y < -15
			|| vectMissileEnnemi[i].cercle.getPosition().x > WINDOWX + 15 || vectMissileEnnemi[i].cercle.getPosition().x < -15)
		{
			vectMissileEnnemi.erase(vectMissileEnnemi.begin() + i);
		}
		if (Keyboard::isKeyPressed(Keyboard::M))
			vectMissileEnnemi.clear();
	}

}

