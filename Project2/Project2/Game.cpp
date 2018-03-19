#include "Game.h"

using namespace sf;
using namespace std;

void afficherVector(vector<Entite> vecteur, RenderWindow window)
{
	for (int i = 0; i < vecteur.size(); i++)
	{
		window.draw(vecteur[i].sprite);

	}
}




Game::Game()
{
}


Game::~Game()
{
}

void Game::jeu()
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
	Clock ennemiPop;
	bool shoot1=false;
	bool shoot2 = false;
	bool shoot3 = false;



	RenderWindow window(VideoMode(700, 700), "GalacticClash");
	window.setPosition(Vector2i(350, 0));
	window.setMouseCursorVisible(0);

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	//décors
	Etoiles etoile1(Color::White, 1.5);
	Etoiles etoile2(Color(250, 250, 255, 150), 1);
	int etoilesSpawn = 0;
	int spawn1 = 40;
	vector<Etoiles>etoilesDecors;

	//joueur
	Joueur joueur;
	joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
	Vector2f positionPrecedente;
	
	//explosion
	Explosion explosionJoueur(7);
	Explosion explosionEnnemi(5);
	vector<Explosion>explosions;
	float dureeExplosion = 0.0;
	bool boum = false;

	//ennemis
	Ennemi1 ennemi1;
	ennemi1.sprite.setPosition(100, 0);
	Ennemi2 ennemi2;
	Ennemi3 ennemi3;
	vector<Ennemi> ennemis;
	

	int ennemiSpawn1 = 0;
	int ennemiSpawn2 = 0;
	int ennemiSpawn3 = 0;

	int spawn2 = 10;
	float ennemiInc = 0;
	bool revenir = false;
	int dureeExplosionEnnemi = 0;



	//missiles
	Missile missile;
	vector<Missile> missiles;

	Missile missileEnnemi;
	vector<Missile> missilesEnnemis;


	//bords de l'écran
	Bordure bordureGauche(Vector2f(1.f, 0.f), Vector2f(1.f, WINDOWY));
	Bordure bordureDroite(Vector2f(WINDOWX, 0.f), Vector2f(1.f, WINDOWY));
	Bordure bordureHaut(Vector2f(0.f, 0.f), Vector2f(WINDOWX, 1.f));
	Bordure bordureBas(Vector2f(0.f, WINDOWY + 5), Vector2f(WINDOWX, 1.f));

	//Texte "Perdu & appuyez sur espace"
	Texte textePerdu(50, Vector2f(WINDOWX/2-55, WINDOWY/2-50), "PERDU !");
	Texte texteAppuyezEspace(40, Vector2f(WINDOWX/2-210, WINDOWY/2+30), "Appuyez sur ESPACE pour rejouer");

	//Texte Score
	Texte score(30, Vector2f(10.f, 5.f), "0");
	string scoreString;
	int scoreInt = 0;

	//Texte PV
	string pointsVieString = "VIES : " + to_string(joueur.pv);
	Texte pointsVie(30, Vector2f(WINDOWX-80, 5), pointsVieString);

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


		//decors/////////////////////////////////////////////////////////////////////
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

		//Déplacement et animation joueur//////////////////////////////////////////////////////
		
		//cout << "joueur : " << joueur.boom<< endl;

		joueur.joueurPositionPrecedente = joueur.sprite.getPosition(); //permet de récupérer la position du joueur avant déplacement afin de gérer les collisions avec le bord de l'écran
		joueur.sprite.move(joueur.deplacement().x, joueur.deplacement().y);

		//HitBox du joueur//////////////////////////////////////////////////////////////////
		joueur.hitBoxJoueur.setPosition(Vector2f(joueur.sprite.getPosition().x, joueur.sprite.getPosition().y));

		//Collision joueur/bord écran/////////////////////////////////////////////////////////////////////
		joueur.collisionBordure(bordureGauche);
		joueur.collisionBordure(bordureDroite);
		joueur.collisionBordure(bordureHaut);
		joueur.collisionBordure(bordureBas);

		//Explosion /////////////////////////////////////////////////////////////////
		explosionJoueur.explosion.setPosition(Vector2f(joueur.sprite.getPosition().x + 1, joueur.sprite.getPosition().y + 7));
		explosionJoueur.trigger = joueur.boom;
		explosionJoueur.animation();

		//Tir/////////////////////////////////////////////////////////////////////

		if (Keyboard().isKeyPressed(Keyboard::LControl) && joueur.tirOK == true && joueur.move == true)
		{
			missile.forme.setPosition(Vector2f(joueur.sprite.getPosition().x - missile.forme.getSize().x / 2, joueur.sprite.getPosition().y - joueur.sprite.getTextureRect().height));
			missiles.push_back(missile);
			joueur.tirOK = false;
		}
		else if (!Keyboard().isKeyPressed(Keyboard::LControl))
		{
			joueur.tirOK = true;
		}

		for (unsigned int i = 0; i < missiles.size(); i++)
		{
			missiles[i].forme.move(0.f, -17.f);

			if (missiles[i].forme.getPosition().y < -10)
			{
				missiles.erase(missiles.begin() + i);
			}
		}

		//Déplacement ennemis	/////////////////////////////////////////////////////////////////////
		

		/*if (Keyboard().isKeyPressed(Keyboard::Num1))
		{
			shoot1 = true;
		}
		else
			shoot1 = false;
		if (Keyboard().isKeyPressed(Keyboard::Num2))
		{
			shoot2 = true;
		}
		else
			shoot2 = false;
		if (Keyboard().isKeyPressed(Keyboard::Num3))
		{
			shoot3 = true;
		}
		else
			shoot3 = false;*/

		if (ennemiSpawn1 < 8)
			ennemiSpawn1++;
		if (ennemiSpawn2 < 30)
			ennemiSpawn2++;
		if (ennemiSpawn3 < 15)
			ennemiSpawn3++;

		if (ennemiSpawn1 >= 8 && shoot1 == true)
		{
			ennemi1.sprite.setPosition(rand() % int(window.getSize().x - ennemi1.sprite.getGlobalBounds().width), 0);
			ennemis.push_back(ennemi1);
			ennemiSpawn1 = 0;
		}
		if (ennemiSpawn2 >= 30 && shoot2 == true)
		{
			ennemi2.sprite.setPosition(rand() % int(window.getSize().x - ennemi2.sprite.getGlobalBounds().width), 0);
			ennemis.push_back(ennemi2);
			ennemiSpawn2 = 0;
		}if (ennemiSpawn3 >= 15 && shoot3 == true)
		{
			ennemi3.sprite.setPosition(rand() % int(window.getSize().x - ennemi3.sprite.getGlobalBounds().width), 0);
			ennemis.push_back(ennemi3);
			ennemiSpawn3 = 0;
		}

		for (unsigned int i = 0; i < ennemis.size(); i++)
		{
			ennemis[i].deplacement();

			if (ennemis[i].sprite.getPosition().y > window.getSize().y + 50)
			{
				ennemis.erase(ennemis.begin() + i);
			}

		}

		if (ennemiPop.getElapsedTime().asSeconds() >= 3)
		{
			shoot3 = true;
		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 6)
		{
			shoot1 = true;
		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 8)
		{
			shoot3 = false;
			shoot1 = false;
		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 10)
		{
			shoot2 = true;
		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 15)
		{
			shoot1 = true;
		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 18)
		{
			shoot1 = false;
			shoot2 = false;
		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 25)
		{
			shoot1 = true;
			shoot2 = true;
			shoot3 = true;

		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 30)
		{
			shoot1 = false;
			shoot2 = false;
			shoot3 = false;

		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 35)
		{
			shoot1 = true;
			shoot2 = true;
			shoot3 = true;

		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 43)
		{
			shoot1 = false;
			shoot2 = false;
			shoot3 = false;

		}
		if (ennemiPop.getElapsedTime().asSeconds() >= 48)
		{
			jeu = GAMEOVER;

		}

		//cout << "timeline : " << ennemiPop.getElapsedTime().asSeconds() << endl;
		//Collisions ennemis/missiles et affichage du score		/////////////////////////////////////////////////////////////////////


		for (unsigned j = 0; j < ennemis.size(); j++)
		{

			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				if (missiles[i].forme.getGlobalBounds().intersects(ennemis[j].sprite.getGlobalBounds()) && ennemis[j].pv > 0)
				{
					
					missiles[i].forme.setSize(Vector2f(0,0));
					ennemis[j].pv--;
					//cout << ennemis[j].pv << endl;

					break;

				}
				if (ennemis[j].pv < 1 && ennemis[j].incrScore == true)
				{
					scoreInt += ennemis[j].points;
					scoreString = to_string(scoreInt);
					score.textString = scoreString;
					ennemis[j].incrScore = false;

				}
				if (ennemis[j].pv <= 0)
				{
					
					ennemis[j].move = false;
					ennemis[j].explosionEnnemi();
					ennemis[j].dégatsJoueur = false;
					if (dureeExplosionEnnemi < 3)
					{
						ennemis[j].boom = false;

						dureeExplosionEnnemi++;
					}

					if (dureeExplosionEnnemi >= 3)
					{
						ennemis[j].boom = true;

						dureeExplosionEnnemi = 0;
					}

					break;
				}

			}
		}

		//Collision joueur/ennemis /////////////////////////////////////////////////////////////////////


		for (unsigned int i = 0; i < ennemis.size(); i++)
		{
			if (ennemis[i].dégatsJoueur == true)
			{
				joueur.collisionEnnemi(ennemis[i]);
				pointsVie.textString = "VIES : " + to_string(joueur.pv);
			}

		}
		if (joueur.tempsRestart == true)
		{
			temps.restart();
			joueur.tempsRestart = false;
		}

		Time elapsed = temps.getElapsedTime();

		if (elapsed.asSeconds() > 0.8 && joueur.move == false)
		{
			temps.restart();
			
			joueur.joueurMort();
		}

		if (elapsed.asSeconds() > 1.5)
		{
			joueur.sprite.setColor(Color(255, 255, 255, 255));
			joueur.invincible = false;
		}

		if (joueur.pv < 0)
		{
			jeu = GAMEOVER;
		}

		//Affichage ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		switch (jeu)
		{
		case JEU:

			window.clear(Color(30, 0, bleu));
			if (back == false)
				bleu += 0.04;
			if (bleu > 100)
				back = true;
			if (back == true)
				bleu -= 0.04;
			if (bleu < 20)
				back = false;

			for (unsigned int i = 0; i < etoilesDecors.size(); i++)
			{
				window.draw(etoilesDecors[i].forme);
			}

			
			window.draw(joueur.sprite);
			window.draw(joueur.hitBoxJoueur);
			bordureGauche.contruire(window);
			bordureDroite.contruire(window);
			bordureHaut.contruire(window);
			bordureBas.contruire(window);

			//Boucle d'affichage des ennemis
			
			for (int i = 0; i < ennemis.size(); i++)
			{
				window.draw(ennemis[i].sprite);

			}
			
			//Boucle d'affichage des missiles
			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				window.draw(missiles[i].forme);
			}

			if (joueur.boom == true)
			{
				window.draw(explosionJoueur.explosion);

			}

			//Affichage des textes
			window.draw(score.ecrireTexte());
			window.draw(pointsVie.ecrireTexte());


			window.display();
			break;

		case GAMEOVER:
			window.clear();

			//window.draw(textePerdu.ecrireTexte());

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

			joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
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
				ennemiPop.restart();
			}
			break;
		}
	}
	
}
