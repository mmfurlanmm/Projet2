#include "Game.h"
#include <math.h>
#include <algorithm>

using namespace sf;
using namespace std;

enum { JEU, GAMEOVER, TITRE, SCORE };

void afficherVector(vector<Entite> vecteur, RenderWindow &window)
{
	for (int i = 0; i < vecteur.size(); i++)
	{
		window.draw(vecteur[i].forme);
		window.draw(vecteur[i].sprite);
		window.draw(vecteur[i].cercle);
	}
}
void afficherVector(vector<Etoiles> vecteur, RenderWindow &window)
{
	for (int i = 0; i < vecteur.size(); i++)
	{
		window.draw(vecteur[i].forme);
		window.draw(vecteur[i].sprite);
		window.draw(vecteur[i].cercle);
	}
}
void afficherVector(vector<Ennemi> vecteur, RenderWindow &window)
{
	for (int i = 0; i < vecteur.size(); i++)
	{
		window.draw(vecteur[i].forme);
		window.draw(vecteur[i].sprite);
		window.draw(vecteur[i].cercle);
	}

}

void reinitialisationLancementDesEnnemis(bool shoot1, bool shoot12, bool shoot2, bool shoot3)
{
	shoot1 = false;
	shoot12 = false;

	shoot2 = false;
	shoot3 = false;

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


	bool goOn = false;//goOn = false emp�che le joueur de passer � un autre �tat du jeu
	bool back = false;
	bool move = true;
	bool invincible = false;

	int jeu = TITRE; //Par d�faut, la variable de gestion d'�v�nement est � "TITRE"
	int niveauEnCours = 0;
	//Gestion du temps
	Clock temps; //horloge principale du jeu
	Clock tempsTitre;
	Clock cadenceCanon;
	Clock tempsActivationCanon;
	Clock tempsExplosion;
	sf::Clock frame;

	Clock megaBombeClock;
	Clock megaBombExplosionsClock;
	bool megaBombeActive = false;
	bool megaBombeRechargee = true;
	int megaBombeCmpt = 0;





	RenderWindow window(VideoMode(WINDOWX, WINDOWY), "GalacticClash");
	window.setPosition(Vector2i(350, 0));
	window.setMouseCursorVisible(0);

	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(300);

	//niveaux
	//Niveaux niveaux;

	//d�cors
	Etoiles etoile1(Color::White, 4);
	Etoiles etoile2(Color(250, 250, 255, 150), 2.5);
	int etoilesSpawn = 0;
	int spawn1 = 35;
	vector<Etoiles>etoilesDecors;

	//joueur
	//Joueur joueur;
	niveaux.joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
	Vector2f positionPrecedente; // pour la gestion des collisions

	//explosion
	Explosion explosionJoueur(7);
	Explosion megaBombeExplosion(14);
	megaBombeExplosion.explosion.setColor(Color(255, 255, 255, 150));
	
	vector<Explosion> explosions;
	float dureeExplosion = 0.0;
	bool boum = false;

	//ennemis

	int dureeExplosionEnnemi = 0;

	//missiles
	Missile missile;
	missile.cercle.setPointCount(4);
	missile.cercle.setScale(0.9, 1.3);
	Missile canon;
	canon.forme.setSize(Vector2f(0, 0));
	vector<Entite> missiles;

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
	string pointsVieString = "VIES : " + to_string(niveaux.joueur.pv);
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

		Time frameRate = frame.restart();


		//cout << "frame rate : " << 1.f / frameRate.asMilliseconds() * 1000 << endl;
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

		niveaux.joueur.joueurPositionPrecedente = niveaux.joueur.sprite.getPosition(); //permet de r�cup�rer la position du joueur avant d�placement afin de g�rer les collisions avec le bord de l'�cran
		niveaux.joueur.sprite.move(niveaux.joueur.deplacement().x, niveaux.joueur.deplacement().y);

		//HitBox du joueur//////////////////////////////////////////////////////////////////
		niveaux.joueur.hitBoxJoueur.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x, niveaux.joueur.sprite.getPosition().y));

		//Collision joueur/bord �cran/////////////////////////////////////////////////////////////////////
		niveaux.joueur.collisionBordure(bordureGauche);
		niveaux.joueur.collisionBordure(bordureDroite);
		niveaux.joueur.collisionBordure(bordureHaut);
		niveaux.joueur.collisionBordure(bordureBas);

		//Explosion /////////////////////////////////////////////////////////////////
		explosionJoueur.explosion.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x + 1, niveaux.joueur.sprite.getPosition().y + 7));
		explosionJoueur.trigger = niveaux.joueur.boom;
		explosionJoueur.animation();
		if (megaBombeRechargee == false && megaBombeCmpt<3)
		{
			if (megaBombExplosionsClock.getElapsedTime().asMilliseconds() > 3)
			{
				megaBombeExplosion.explosion.setPosition(Vector2f(rand() % int(WINDOWX), rand() % int(WINDOWY)));
				explosions.push_back(megaBombeExplosion);
			}
			megaBombExplosionsClock.restart();
		}
		if (megaBombeCmpt >=3)
			explosions.clear();
		for (int i = 0; i < explosions.size(); i++)
		{
				
			explosions[i].animation();
		}
		

		//Tir/////////////////////////////////////////////////////////////////////


		niveaux.joueur.jaugecanon();
		if (Keyboard::isKeyPressed(Keyboard::LControl) && niveaux.joueur.tirOK == true && niveaux.joueur.move == true)
		{
			missile.cercle.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x - missile.cercle.getRadius(), niveaux.joueur.sprite.getPosition().y - niveaux.joueur.sprite.getTextureRect().height));
			missiles.push_back(missile);
			niveaux.joueur.tirOK = false;
			tempsActivationCanon.restart();

		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl) && niveaux.joueur.move == true && tempsActivationCanon.getElapsedTime().asSeconds() > 0.4)
		{
			if (cadenceCanon.getElapsedTime().asMilliseconds() >= 50)
			{
				niveaux.joueur.canonActif = true;
				if (niveaux.joueur.valeurJaugeCanon > 0)
				{
					canon.cercle.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x - 15 + +rand() % 10, niveaux.joueur.sprite.getPosition().y - niveaux.joueur.sprite.getTextureRect().height * 3));
					missiles.push_back(canon);
					cadenceCanon.restart();
				}
			}
		}

		else if (!Keyboard::isKeyPressed(Keyboard::LControl))
		{
			niveaux.joueur.tirOK = true;
			niveaux.joueur.canonActif = false;
		}





		for (unsigned int i = 0; i < missiles.size(); i++)
		{

			missiles[i].cercle.move(0.f, -22.f);


			if (missiles[i].forme.getPosition().y < -10 || missiles[i].cercle.getPosition().y < -10)
			{
				missiles.erase(missiles.begin() + i);
			}
		}

		//Ennemis	/////////////////////////////////////////////////////////////////////

		//Gestion des niveaux


		switch (niveauEnCours)
		{
		case 1:
			niveaux.niveau1();

			break;
		case 2:
			niveaux.niveau2();

			break;
		case 3:
			niveaux.niveau3();

			break;
		case 99:
			niveaux.niveauTest();

			break;

		}

		if (niveaux.fini == true)
		{
			reinitialisationLancementDesEnnemis(niveaux.shoot1, niveaux.shoot2, niveaux.shoot3, niveaux.shoot12);
			jeu = SCORE;

		}



		//Collisions ennemis/missiles et affichage du score		/////////////////////////////////////////////////////////////////////


		for (unsigned j = 0; j < niveaux.ennemis.size(); j++)
		{



			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				if (missiles[i].cercle.getGlobalBounds().intersects(niveaux.ennemis[j].sprite.getGlobalBounds()) && niveaux.ennemis[j].pv > 0)
				{


					missiles[i].cercle.setRadius(0);

					niveaux.ennemis[j].hit = true;
					niveaux.ennemis[j].pv--;

					break;

				}




			}
			if (niveaux.ennemis[j].pv < 1 && niveaux.ennemis[j].incrScore == true)
			{
				scoreInt += niveaux.ennemis[j].points;
				scoreString = to_string(scoreInt);
				score.textString = scoreString;
				niveaux.ennemis[j].incrScore = false;
				niveaux.ennemis[j].hit = false;


			}
			if (niveaux.ennemis[j].pv < 1)
			{
				niveaux.ennemis[j].explosionEnnemi();
				niveaux.ennemis[j].move = false;
				niveaux.ennemis[j].d�gatsJoueur = false;

			}

		}
		if (Keyboard::isKeyPressed(Keyboard::LShift) && megaBombeRechargee == true && megaBombeActive == false)
		{
			megaBombeActive = true;
			megaBombeRechargee = false;
		}
		

		if (megaBombeActive == true)
		{
			if (megaBombeClock.getElapsedTime().asMilliseconds() > 400 && megaBombeCmpt < 3)
			{
				for (unsigned int j = 0; j < niveaux.ennemis.size(); j++)
					niveaux.ennemis[j].pv -= 5;
				megaBombeCmpt++;
				megaBombeClock.restart();

			}
		}
		if (megaBombeClock.getElapsedTime().asMilliseconds() > 400 && !Keyboard::isKeyPressed(Keyboard::LShift))
		{
			megaBombeActive = false;
			megaBombeRechargee = true;
			megaBombeCmpt = 0;
		}
		
			
		
		cout << "clock" << megaBombExplosionsClock.getElapsedTime().asSeconds() << endl;
		






		for (int i = 0; i < niveaux.ennemis.size(); i++)
		{
			niveaux.ennemis[i].ennemiHit();
		}

		//Collision joueur/ennemis /////////////////////////////////////////////////////////////////////


		for (unsigned int i = 0; i < niveaux.ennemis.size(); i++)
		{
			if (niveaux.ennemis[i].d�gatsJoueur == true)
			{
				niveaux.joueur.collisionEnnemi(niveaux.ennemis[i]);
				pointsVie.textString = "VIES : " + to_string(niveaux.joueur.pv);

			}
			for (int j = 0; j < niveaux.vectMissileEnnemi.size(); j++)
			{
				if (niveaux.vectMissileEnnemi[j].d�gatsJoueur == true)
				{
					niveaux.joueur.collisionEnnemi(niveaux.vectMissileEnnemi[j]);
					pointsVie.textString = "VIES : " + to_string(niveaux.joueur.pv);

				}

			}

		}
		if (niveaux.joueur.tempsRestart == true)
		{
			temps.restart();
			niveaux.joueur.tempsRestart = false;
		}

		Time elapsed = temps.getElapsedTime();

		if (elapsed.asSeconds() > 0.8 && niveaux.joueur.move == false)
		{
			niveaux.joueur.joueurRepopInvincible(temps);
		}


		if (elapsed.asSeconds() > 2.5)
		{
			niveaux.joueur.joueurNormalApresInvincible();
		}

		if (niveaux.joueur.pv < 0)
		{
			reinitialisationLancementDesEnnemis(niveaux.shoot1, niveaux.shoot2, niveaux.shoot3, niveaux.shoot12);
			niveaux.clock1.restart();
			jeu = GAMEOVER;
		}

		//Affichage ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		switch (jeu)
		{
		case TITRE:


			window.clear();

			window.draw(ecranTitre1.ecrireTexte());
			window.draw(ecranTitre2.ecrireTexte());
			if (tempsTitre.getElapsedTime().asSeconds() > 3)
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

			reinitialisationLancementDesEnnemis(niveaux.shoot1, niveaux.shoot2, niveaux.shoot3, niveaux.shoot12);


			niveaux.ennemis.clear();
			niveaux.vectMissileEnnemi.clear();
			missiles.clear();


			//On lance le jeu en appuyant sur espace (un message l'indique � l'�cran)


			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true)
			{
				niveaux.clock1.restart();
				niveaux.bossGo = false;
				niveaux.go = false;
				niveauEnCours = 1;
				jeu = JEU;
			}


			break;

		case JEU:

			//Permet de faire varier la couleur du fond en fonction du niveau
			switch (niveauEnCours)
			{
			case 1:
				window.clear(Color(0, 10, 20));
				break;
			case 2:
				window.clear(Color(30, 0, 50));
				break;
			case 3:
				window.clear(Color(25, 25, 50));
				break;
			default:
				window.clear(Color(0, 20, 30));
				break;
			}

			//Affichage du fond �toil�
			afficherVector(etoilesDecors, window);

			//Affichage des missiles
			afficherVector(missiles, window);
			afficherVector(niveaux.vectMissileEnnemi, window);

			//Affichage du joueur
			window.draw(niveaux.joueur.sprite);
			window.draw(niveaux.joueur.hitBoxJoueur);

			//Construction des bords de l'ecran
			bordureGauche.contruire(window);
			bordureDroite.contruire(window);
			bordureHaut.contruire(window);
			bordureBas.contruire(window);

			//Affichage des ennemis
			afficherVector(niveaux.ennemis, window);


			//Condition pour afficher l'explosion du joueur
			if (niveaux.joueur.boom == true)
			{
				window.draw(explosionJoueur.explosion);
			}
			for (int i = 0; i < explosions.size(); i++)
			{
				window.draw(explosions[i].explosion);
			}

			//Affichage des textes
			window.draw(score.ecrireTexte());
			window.draw(pointsVie.ecrireTexte());
			window.draw(niveaux.joueur.formeJaugeCanon);
			window.draw(niveaux.joueur.contourJaugeCanon);


			break;

		case SCORE:
			window.clear();

			window.draw(ecranScore.ecrireTexte());
			niveaux.fini = false;//

			niveaux.joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
			goOn = false;

			//Permet de bloquer l'�cran "GAGNE" pendant une certaine dur�e
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(ecranScore2.ecrireTexte());
				goOn = true;
			}

			niveaux.ennemis.clear();
			missiles.clear();
			reinitialisationLancementDesEnnemis(niveaux.shoot1, niveaux.shoot2, niveaux.shoot3, niveaux.shoot12);
			niveaux.ennemi1.tirOk = false;
			niveaux.ennemi12.tirOk = false;
			niveaux.ennemi2.tirOk = false;
			niveaux.ennemi3.tirOk = false;
			//
			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true)
			{
				niveaux.clock1.restart();

				niveaux.bossGo = false;
				niveaux.go = false;
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
			niveaux.joueur.pv = PVORIGINE;
			pointsVieString = "VIES : " + to_string(niveaux.joueur.pv);
			pointsVie.textString = pointsVieString;

			niveaux.joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
			goOn = false;

			//Permet de bloquer l'�cran "PERDU" pendant une certaine dur�e
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(texteAppuyezEspace.ecrireTexte());
				goOn = true;
			}

			reinitialisationLancementDesEnnemis(niveaux.shoot1, niveaux.shoot2, niveaux.shoot3, niveaux.shoot12);
			niveaux.ennemi1.tirOk = false;
			niveaux.ennemi12.tirOk = false;
			niveaux.ennemi2.tirOk = false;
			niveaux.ennemi3.tirOk = false;



			niveaux.ennemis.clear();
			missiles.clear();

			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true)
			{
				niveauEnCours = 1;
				niveaux.bossGo = false;
				niveaux.go = false;
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
