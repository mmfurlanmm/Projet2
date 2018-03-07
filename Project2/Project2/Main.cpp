#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Joueur.h"
#include "Ennemi.h"
#include "Ennemi1.h"
#include "Ennemi2.h"
#include "Ennemi3.h"
#include "Etoiles.h"
#include "Texte.h"
#include "Bordure.h"
#include "Missile.h"


using namespace sf;
using namespace std;

enum { JEU, GAMEOVER };//Gestion des évennements du jeu


int main()
{
	srand(time(NULL));

	//Variables diverses
	float bleu = 20;
	bool back = false;
	bool move = true;
	bool invincible = false;
	int jeu = JEU; //Par défaut, la variable de gestion d'évennement est à "JEU"
	//Gestion du temps
	Clock temps;

	RenderWindow window(VideoMode(600, 700), "StarCrashAnnihilator");
	window.setPosition(Vector2i(350, 0));
	window.setMouseCursorVisible(0);
	
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	View vue(Vector2f(300, 350), Vector2f(600, 700));

	//décors
	Etoiles etoile1(Color::White, 1.5);
	Etoiles etoile2(Color(250, 250, 255, 150), 1);
	int etoilesSpawn = 40;
	int spawn1 = 40;
	vector<Etoiles>etoilesDecors;

	//joueur
	Joueur joueur;
	Vector2f positionOrigine(window.getSize().x / 2, window.getSize().y - 30);
	joueur.spriteJoueur.setPosition(positionOrigine);
	Vector2f positionPrecedente;
	
	//explosion
	sf::Texture texture;
	sf::Sprite explosion;
	if (!texture.loadFromFile("Images/explosion.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}
	explosion.setTexture(texture);
	explosion.setTextureRect(IntRect(0, 0, 15, 15));
	explosion.setScale(6, 6);
	explosion.setOrigin(explosion.getTextureRect().width / 2, explosion.getTextureRect().height);

	int inc = 0;
	int dureeExplosion = 20;
	


	//ennemis
	Ennemi1 ennemi1(Vector2f(0.f, 15.f));
	Ennemi2 ennemi2(Vector2f(0.f, 3.f), 2);
	Ennemi3 ennemi3(Vector2f(0.f, 5.f));
	vector<Ennemi> ennemis;
	int ennemiSpawn = 0;
	int spawn2 = 30;

	
	Missile missile;
	
	vector<RectangleShape> missiles;
	

	//bords de l'écran
	Bordure bordureGauche(Vector2f(1.f, 0.f), Vector2f(1.f, window.getSize().y));
	Bordure bordureDroite(Vector2f(window.getSize().x, 0.f), Vector2f(1.f, window.getSize().y));
	Bordure bordureHaut(Vector2f(0.f, 0.f), Vector2f(window.getSize().x, 1.f));
	Bordure bordureBas(Vector2f(0.f, window.getSize().y + 5), Vector2f(window.getSize().x, 1.f));

	//Texte Perdu
	Vector2f perduPosition(window.getSize().x / 2 - 55, window.getSize().y / 2 - 50);
	Texte textePerdu(50, perduPosition, "PERDU !");
	Vector2f appuyezEspacePosition(window.getSize().x / 2 - 210, window.getSize().y / 2 +30);
	Texte texteAppuyezEspace(40, appuyezEspacePosition, "Appuyez sur ESPACE pour rejouer");
	

		

	//Score
	Vector2f scorePosition(10.f, 5.f);
	Texte score(30, scorePosition, "0");
	string scoreString;
	int scoreInt = 0;

	//Texte PV
	Vector2f pointViePosition(window.getSize().x - 80, 5);
	string pointsVieString = "VIES : " + to_string(joueur.pv);
	Texte pointsVie(30, pointViePosition, pointsVieString);

	//Boucle de jeu
	while (window.isOpen())
	{
		Event event;
		//Gestion de la saisie utilisateur
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard().isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			
		}
		
		//decors
		if (etoilesSpawn < spawn1)
			etoilesSpawn++;

		if (etoilesSpawn >= spawn1)
		{
			etoile1.forme.setPosition(rand() % int(window.getSize().x), 0);
			etoile2.forme.setPosition(rand() % int(window.getSize().x), 0);

			etoilesDecors.push_back(etoile1);
			etoilesDecors.push_back(etoile2);

			etoilesSpawn = 0;
		}

		for (unsigned int i = 0; i < etoilesDecors.size(); i++)
		{

			etoilesDecors[i].forme.move(0.f, etoilesDecors[i].vitesse);
		
			if (etoilesDecors[i].forme.getPosition().y > window.getSize().y)
			{
				etoilesDecors.erase(etoilesDecors.begin() + i);
			}
		}

		//Déplacement joueur

		joueur.joueurPositionPrecedente = joueur.spriteJoueur.getPosition();
		joueur.spriteJoueur.move(joueur.deplacement().x, joueur.deplacement().y);

		//HitBox du joueur
		joueur.hitBoxJoueur.setPosition(Vector2f(joueur.spriteJoueur.getPosition().x, joueur.spriteJoueur.getPosition().y));

		//Collision joueur/bord écran
		joueur.collisionBordure(bordureGauche);
		joueur.collisionBordure(bordureDroite);
		joueur.collisionBordure(bordureHaut);
		joueur.collisionBordure(bordureBas);

		//Tir

		if (Keyboard().isKeyPressed(Keyboard::LControl) && joueur.tirOK == true && joueur.move == true)
		{
			missile.missile.setPosition(Vector2f(joueur.spriteJoueur.getPosition().x - missile.missile.getSize().x / 2, joueur.spriteJoueur.getPosition().y - joueur.spriteJoueur.getTextureRect().height));
			missiles.push_back(missile.missile);
			joueur.tirOK = false;
		}
		else if (!Keyboard().isKeyPressed(Keyboard::LControl))
		{
			joueur.tirOK = true;
		} 
		
		for (unsigned int i = 0; i < missiles.size(); i++)
		{
			missiles[i].move(0.f, -17.f);

			if (missiles[i].getPosition().y < -10)
			{
				missiles.erase(missiles.begin() + i);
			}
		}

		//Déplacement ennemis

		if (ennemiSpawn < spawn2)
			ennemiSpawn++;

		if (ennemiSpawn >= spawn2)
		{
			ennemi1.spriteEnnemi.setPosition(rand() % int(window.getSize().x - ennemi1.spriteEnnemi.getGlobalBounds().width), 0);
			ennemi2.spriteEnnemi.setPosition(rand() % int(window.getSize().x - ennemi2.spriteEnnemi.getGlobalBounds().width), 0);
			ennemi3.spriteEnnemi.setPosition(rand() % int(window.getSize().x - ennemi3.spriteEnnemi.getGlobalBounds().width), 0);


			ennemis.push_back(ennemi1);
			ennemis.push_back(ennemi2);
			ennemis.push_back(ennemi3);

			ennemiSpawn = 0;
		}

		for (unsigned int i = 0; i < ennemis.size(); i++)
		{
			ennemis[i].deplacement();

			if (ennemis[i].spriteEnnemi.getPosition().y > window.getSize().y + 50)
			{
				ennemis.erase(ennemis.begin() + i);
			}

		}

		//Collisions ennemis/missiles et affichage du score


		for (unsigned i = 0; i < missiles.size(); i++)
		{
			for (unsigned int j = 0; j < ennemis.size(); j++)
			{
				if (missiles[i].getGlobalBounds().intersects(ennemis[j].spriteEnnemi.getGlobalBounds())&& ennemis[j].pv>1)
				{
					
					missiles.erase(missiles.begin() + i);
					ennemis[j].pv--;
					break;

				}
				else if (missiles[i].getGlobalBounds().intersects(ennemis[j].spriteEnnemi.getGlobalBounds()))
				{
					missiles.erase(missiles.begin() + i);
					ennemis.erase(ennemis.begin() + j);
					//Score
					scoreInt += 100;
					scoreString = to_string(scoreInt);
					score.textString = scoreString;

					break;

				}
				
			}
		}

		//Collision joueur/ennemis
		
		//Explosion
		explosion.setPosition(joueur.spriteJoueur.getPosition().x + 1, joueur.spriteJoueur.getPosition().y + 7);
		
		explosion.setTextureRect(IntRect(inc, 0, 14, 14));
		if (dureeExplosion < 5)
			dureeExplosion++;
		if (dureeExplosion >= 5)
		{
			inc += 14;
			if (inc > 56)
				inc = 0;
			dureeExplosion = 0;
		}

		for (unsigned int i = 0; i < ennemis.size(); i++)
		{
			joueur.collisionEnnemi(ennemis[i]);
			pointsVie.textString = "VIES : " + to_string(joueur.pv);
			
		}
		if (joueur.tempsRestart == true)
		{
			temps.restart();
			joueur.tempsRestart = false;
		}
		
		Time elapsed = temps.getElapsedTime();
		std::cout << elapsed.asSeconds() << endl;
		cout << invincible << endl;

		if (elapsed.asSeconds() > 0.8 && joueur.move == false)
		{
			temps.restart();
			joueur.boom = false;
			joueur.spriteJoueur.setColor(Color(255, 55, 55, 80));
			joueur.spriteJoueur.setPosition(positionOrigine);
			joueur.move = true;
		}
		

		if (elapsed.asSeconds() > 1.5)
		{
			joueur.spriteJoueur.setColor(Color(255, 255, 255, 255));
			joueur.invincible = false;
		}

		if (joueur.pv < 0)
		{
			jeu = GAMEOVER;
		}

		//Affichage


		switch (jeu)
		{
		case JEU:
			
			window.clear(Color(20,0,bleu));
			if (back == false)
				bleu += 0.01;
			if (bleu > 50)
				back = true;
			if (back == true)
				bleu -= 0.01;
			if (bleu < 20)
				back = false;

			window.setView(vue);

			for (unsigned int i = 0; i < etoilesDecors.size(); i++)
			{
				window.draw(etoilesDecors[i].forme);
			}
			
			window.draw(joueur.spriteJoueur);
			window.draw(joueur.hitBoxJoueur);
			bordureGauche.contruire(window);
			bordureDroite.contruire(window);
			bordureHaut.contruire(window);
			bordureBas.contruire(window);

			//Boucle d'affichage des ennemis
			for (unsigned int i = 0; i < ennemis.size(); i++)
			{
				window.draw(ennemis[i].spriteEnnemi);
			}

			//Boucle d'affichage des missiles
			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				window.draw(missiles[i]);
			}
			
			if (joueur.boom == true)
				window.draw(explosion);
			
			window.draw(score.ecrireTexte());
			window.draw(pointsVie.ecrireTexte());


			window.display();
			break;

		case GAMEOVER:
			window.clear();

			window.draw(textePerdu.ecrireTexte());

			scoreInt = 0;
			score.textString = "0";
			joueur.pv = 3;
			pointsVieString = "VIES : " + to_string(joueur.pv);
			pointsVie.textString = pointsVieString;
			for (unsigned int i = 0; i < ennemis.size(); i++)
			{
				ennemis.erase(ennemis.begin(), ennemis.end());
			}
			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				missiles.erase(missiles.begin(), missiles.end());
			}

			joueur.spriteJoueur.setPosition(positionOrigine);
			bool goOn = false;

			//Permet de bloquer l'écran "PERDU" pendant une certaine durée
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(texteAppuyezEspace.ecrireTexte());
				goOn = true;
			}

			window.display();
			if (Keyboard().isKeyPressed(Keyboard::Space) && goOn == true)
			{
				jeu = JEU;
			}
			break;
		}
	}
	return 0;
}
