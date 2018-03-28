#include "Game.h"
#include <math.h>

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
	float rouge = 20;
	float vert = 20;
	float bleu = 20;


	bool goOn;//goOn = false emp�che le joueur de passer � un autre �tat du jeu
	bool back = false;
	bool move = true;
	bool invincible = false;
	int jeu = TITRE; //Par d�faut, la variable de gestion d'�v�nement est � "TITRE"
	int niveauEnCours = 0;
	//Gestion du temps
	Clock temps; //horloge principale du jeu
	Clock tempsTitre;



	RenderWindow window(VideoMode(700, 800), "GalacticClash");
	window.setPosition(Vector2i(350, 0));
	window.setMouseCursorVisible(0);

	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(1000);

	//niveaux
	Niveaux niveaux;

	//d�cors
	Etoiles etoile1(Color::White, 4);
	Etoiles etoile2(Color(250, 250, 255, 150), 2.5);
	int etoilesSpawn = 0;
	int spawn1 = 35;
	vector<Etoiles>etoilesDecors;

	//joueur
	Joueur joueur;
	joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
	Vector2f positionPrecedente; // pour la gestion des collisions

	//explosion
	Explosion explosionJoueur(7);
	Explosion explosionEnnemi(5);
	vector<Explosion>explosions;
	float dureeExplosion = 0.0;
	bool boum = false;

	//ennemis

	int dureeExplosionEnnemi = 0;

	//missiles
	Missile missile;
	vector<Missile> missiles;

	//bords de l'�cran
	Bordure bordureGauche(Vector2f(1.f, 0.f), Vector2f(1.f, WINDOWY));
	Bordure bordureDroite(Vector2f(WINDOWX, 0.f), Vector2f(1.f, WINDOWY));
	Bordure bordureHaut(Vector2f(0.f, 0.f), Vector2f(WINDOWX, 1.f));
	Bordure bordureBas(Vector2f(0.f, WINDOWY + 5), Vector2f(WINDOWX, 1.f));

	//Texte "Perdu & appuyez sur espace"
	Texte textePerdu(180, Vector2f(WINDOWX / 2, 300), "PERDU !");
	Texte texteAppuyezEspace(40, Vector2f(WINDOWX / 2, 650), "Appuyez sur ESPACE pour rejouer");

	//Texte Score
	Texte score(30, Vector2f(50.f, 5.f), "0");
	string scoreString;
	int scoreInt = 0;

	//Texte PV
	string pointsVieString = "VIES : " + to_string(joueur.pv);
	Texte pointsVie(30, Vector2f(WINDOWX - 50, 5), pointsVieString);

	//Texte titre
	Texte ecranTitre1(180, Vector2f(WINDOWX / 2, 250), "GALACTIC");
	Texte ecranTitre2(180, Vector2f(WINDOWX / 2, 360), "CLASH");
	Texte ecranTitre3(40, Vector2f(WINDOWX / 2, 650), "Appuyez sur ESPACE pour jouer");

	//Texte ecran score
	Texte ecranScore(180, Vector2f(WINDOWX / 2, 250), "GAGNE !!");
	Texte ecranScore2(40, Vector2f(WINDOWX / 2, 650), "Appuyez sur ESPACE");


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

		//D�placement et animation joueur//////////////////////////////////////////////////////

		joueur.joueurPositionPrecedente = joueur.sprite.getPosition(); //permet de r�cup�rer la position du joueur avant d�placement afin de g�rer les collisions avec le bord de l'�cran
		joueur.sprite.move(joueur.deplacement().x, joueur.deplacement().y);

		//HitBox du joueur//////////////////////////////////////////////////////////////////
		joueur.hitBoxJoueur.setPosition(Vector2f(joueur.sprite.getPosition().x, joueur.sprite.getPosition().y));

		//Collision joueur/bord �cran/////////////////////////////////////////////////////////////////////
		joueur.collisionBordure(bordureGauche);
		joueur.collisionBordure(bordureDroite);
		joueur.collisionBordure(bordureHaut);
		joueur.collisionBordure(bordureBas);

		//Explosion /////////////////////////////////////////////////////////////////
		explosionJoueur.explosion.setPosition(Vector2f(joueur.sprite.getPosition().x + 1, joueur.sprite.getPosition().y + 7));
		explosionJoueur.trigger = joueur.boom;
		explosionJoueur.animation();

		//Tir/////////////////////////////////////////////////////////////////////

		if (Keyboard::isKeyPressed(Keyboard::LControl) && joueur.tirOK == true && joueur.move == true)
		{
			missile.forme.setPosition(Vector2f(joueur.sprite.getPosition().x - missile.forme.getSize().x / 2, joueur.sprite.getPosition().y - joueur.sprite.getTextureRect().height));
			missiles.push_back(missile);
			joueur.tirOK = false;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::LControl))
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

		//Ennemis	/////////////////////////////////////////////////////////////////////
		
		for (int i = 0; i < niveaux.ennemis.size(); i++)
		{
			niveaux.ennemis[i].tirer();
			if (niveaux.ennemis[i].shoot== true)
			{
				
				niveaux.missileEnnemi.cercle.setPosition(Vector2f(niveaux.ennemis[i].sprite.getPosition().x, niveaux.ennemis[i].sprite.getPosition().y - niveaux.ennemis[i].sprite.getTextureRect().height));
				niveaux.vectMissileEnnemi.push_back(niveaux.missileEnnemi);
				niveaux.missileEnnemi2.cercle.setPosition(Vector2f(niveaux.ennemis[i].sprite.getPosition().x, niveaux.ennemis[i].sprite.getPosition().y - niveaux.ennemis[i].sprite.getTextureRect().height));
				niveaux.vectMissileEnnemi.push_back(niveaux.missileEnnemi2);

			}
			
		}
		for (unsigned int i = 0; i < niveaux.vectMissileEnnemi.size(); i++)
		{
			niveaux.vectMissileEnnemi[i].cercle.move(niveaux.vectMissileEnnemi[i].pattern.x, niveaux.vectMissileEnnemi[i].pattern.y);


			if (niveaux.vectMissileEnnemi[i].cercle.getPosition().y > 810 || niveaux.vectMissileEnnemi[i].cercle.getPosition().y < -10
				|| niveaux.vectMissileEnnemi[i].cercle.getPosition().x > 800 || niveaux.vectMissileEnnemi[i].cercle.getPosition().x < -10)
			{
				niveaux.vectMissileEnnemi.erase(niveaux.vectMissileEnnemi.begin() + i);
			}
		}
		cout << "vect missiles" << niveaux.vectMissileEnnemi.size() << endl;

		//Gestion des niveaux


		switch (niveauEnCours)
		{
		case 1:
			niveaux.niveau1();

			break;
		case 2:
			niveaux.niveau2();

			break;
		case 99:
			niveaux.niveauTest();

			break;

		}



		if (niveaux.fini == true)
		{

			niveaux.shoot1 = false;
			niveaux.shoot2 = false;
			niveaux.shoot3 = false;

			jeu = SCORE;

		}



		//Collisions ennemis/missiles et affichage du score		/////////////////////////////////////////////////////////////////////


		for (unsigned j = 0; j < niveaux.ennemis.size(); j++)
		{


			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				if (missiles[i].forme.getGlobalBounds().intersects(niveaux.ennemis[j].sprite.getGlobalBounds()) && niveaux.ennemis[j].pv > 0)
				{

					missiles[i].forme.setSize(Vector2f(0, 0));
					niveaux.ennemis[j].hit = true;
					niveaux.ennemis[j].pv--;

					break;

				}
				if (niveaux.ennemis[j].pv < 1 && niveaux.ennemis[j].incrScore == true)
				{
					scoreInt += niveaux.ennemis[j].points;
					scoreString = to_string(scoreInt);
					score.textString = scoreString;
					niveaux.ennemis[j].incrScore = false;
					niveaux.ennemis[j].hit = false;


				}
				if (niveaux.ennemis[j].pv <= 0)
				{

					niveaux.ennemis[j].move = false;
					niveaux.ennemis[j].explosionEnnemi();
					niveaux.ennemis[j].d�gatsJoueur = false;
					if (dureeExplosionEnnemi < 3)
					{
						niveaux.ennemis[j].boom = false;

						dureeExplosionEnnemi++;
					}

					if (dureeExplosionEnnemi >= 3)
					{
						niveaux.ennemis[j].boom = true;

						dureeExplosionEnnemi = 0;
					}

					break;
				}

			}
		}

		for (int i = 0; i < niveaux.ennemis.size(); i++)
		{
			niveaux.ennemis[i].ennemiHit();
		}

		//Collision joueur/ennemis /////////////////////////////////////////////////////////////////////


		for (unsigned int i = 0; i < niveaux.ennemis.size(); i++)
		{
			if (niveaux.ennemis[i].d�gatsJoueur == true)
			{
				joueur.collisionEnnemi(niveaux.ennemis[i]);
				pointsVie.textString = "VIES : " + to_string(joueur.pv);

			}
			for (int j = 0; j < niveaux.vectMissileEnnemi.size(); j++)
			{
				if (niveaux.vectMissileEnnemi[j].d�gatsJoueur == true)
				{
					joueur.collisionEnnemi(niveaux.vectMissileEnnemi[j]);
					pointsVie.textString = "VIES : " + to_string(joueur.pv);

				}

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
			niveaux.shoot1 = false;
			niveaux.shoot2 = false;
			niveaux.shoot3 = false;



			niveaux.clock1.restart();
			jeu = GAMEOVER;

		}

		//Affichage ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		switch (jeu)
		{
		case TITRE:

			
			window.clear();
			goOn = false;

			window.draw(ecranTitre1.ecrireTexte());
			window.draw(ecranTitre2.ecrireTexte());
			if (tempsTitre.getElapsedTime().asSeconds() > 2)
			{
				window.draw(ecranTitre3.ecrireTexte());
				goOn = true;
			}

			ecranTitre1.text.setFillColor(Color(rouge, vert, bleu));
			ecranTitre2.text.setFillColor(Color(rouge, vert, bleu));

			//Permet de faire varier la couleur de l'�cran titre
			if (temps.getElapsedTime().asMilliseconds() > 20)
			{
				bleu += 22;
				if (bleu > 150)
					bleu = 20;
				rouge += 20;
				vert += 2;

				temps.restart();
			}
			//D�sactivation des bool�ens permettant de "lancer" les vagues d'ennemis
			niveaux.shoot1 = false;
			niveaux.shoot12 = false;
			niveaux.shoot2 = false;
			niveaux.shoot3 = false;

			niveaux.ennemis.clear();
			niveaux.vectMissileEnnemi.clear();
			missiles.clear();
			

			//On lance le jeu en appuyant sur espace (un message l'indique � l'�cran)
			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true)
			{
				niveaux.clock1.restart();
				niveauEnCours = 2;

				jeu = JEU;

			}

			break;

		case JEU:

			//Permet de faire varier la couleur du fond
			window.clear(Color(30, 0, bleu));
			if (back == false)
				bleu += 0.04;
			if (bleu > 180)
				back = true;
			if (back == true)
				bleu -= 0.04;
			if (bleu < 40)
				back = false;

			//Affichage du fond �toil�
			for (unsigned int i = 0; i < etoilesDecors.size(); i++)
			{
				window.draw(etoilesDecors[i].forme);
			}


			//Affichage des diff�rents objets
			window.draw(joueur.sprite);
			window.draw(joueur.hitBoxJoueur);
			bordureGauche.contruire(window);
			bordureDroite.contruire(window);
			bordureHaut.contruire(window);
			bordureBas.contruire(window);

			//Boucle d'affichage des ennemis

			for (int i = 0; i < niveaux.ennemis.size(); i++)
			{
				window.draw(niveaux.ennemis[i].sprite);

			}

			//Boucle d'affichage des missiles
			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				window.draw(missiles[i].forme);
			}
			//Missiles ennemis
			for (int j = 0; j < niveaux.vectMissileEnnemi.size(); j++)
			{

				window.draw(niveaux.vectMissileEnnemi[j].cercle);
			}
			//Condition pour afficher l'explosion du joueur
			if (joueur.boom == true)
			{
				window.draw(explosionJoueur.explosion);

			}

			//Affichage des textes
			window.draw(score.ecrireTexte());
			window.draw(pointsVie.ecrireTexte());

			break;

		case SCORE:
			window.clear();

			window.draw(ecranScore.ecrireTexte());
			niveaux.fini = false;//

			joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
			goOn = false;

			//Permet de bloquer l'�cran "PERDU" pendant une certaine dur�e
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(ecranScore2.ecrireTexte());
				goOn = true;
			}

			niveaux.ennemis.clear();
			missiles.clear();
			//
			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true)
			{
				niveaux.clock1.restart();
				niveauEnCours++;
				jeu = JEU;
			}

			break;

		case GAMEOVER:
			window.clear();

			window.draw(textePerdu.ecrireTexte());

			niveauEnCours = 0;

			scoreInt = 0;
			score.textString = "0";
			joueur.pv = PVORIGINE;
			pointsVieString = "VIES : " + to_string(joueur.pv);
			pointsVie.textString = pointsVieString;

			joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
			goOn = false;

			//Permet de bloquer l'�cran "PERDU" pendant une certaine dur�e
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(texteAppuyezEspace.ecrireTexte());
				goOn = true;
			}

			niveaux.ennemis.clear();
			missiles.clear();

			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true)
			{


				//ennemiPop.restart();
				niveauEnCours = 1;
				niveaux.clock1.restart();
				jeu = JEU;
			}

			break;

		}
		window.display();
	}

}

void Game::affichage()
{
	
}
