#include "Game.h"
#include <math.h>
#include <algorithm>

using namespace sf;
using namespace std;

enum { JEU, GAMEOVER, TITRE, MISSIONACCOMPLIE, HISCORE };

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
void afficherVector(vector<Explosion> vecteur, RenderWindow &window)
{
	for (int i = 0; i < vecteur.size(); i++)
	{
		window.draw(vecteur[i].explosion);

	}

}


Game::Game()
{

}


Game::~Game()
{
}

void Game::logiqueDuJeu()
{
	srand(time(NULL));

	int jeu = TITRE; //Par défaut, la variable de gestion d'évènement est à "TITRE"
	niveaux.joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);



	sf::RenderWindow window(VideoMode(WINDOWX, WINDOWY), "GalacticClash");
	window.setPosition(Vector2i(350, 0));
	window.setMouseCursorVisible(0);

	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);


	//décors
	Etoiles etoile1(sf::Color::White, 4);
	Etoiles etoile2(sf::Color(250, 250, 255, 150), 2.5);
	vector<Etoiles>etoilesDecors;



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

	//bords de l'écran
	Bordure bordureGauche(Vector2f(1.f, 0.f), Vector2f(1.f, WINDOWY));
	Bordure bordureDroite(Vector2f(WINDOWX, 0.f), Vector2f(1.f, WINDOWY));
	Bordure bordureHaut(Vector2f(0.f, 0.f), Vector2f(WINDOWX, 1.f));
	Bordure bordureBas(Vector2f(0.f, WINDOWY + 5), Vector2f(WINDOWX, 1.f));

	//Texte "Perdu & appuyez sur espace"
	Texte textePerdu(150, Vector2f(WINDOWX / 2, 100), "PERDU !");
	Texte entrezVotreNom(60, Vector2f(WINDOWX / 2, 300), "Entrez votre nom :");
	Texte texteAppuyezEspace(40, Vector2f(WINDOWX / 2, 650), "Appuyez sur START pour valider");
	string nomDuJoueur;

	//Texte Score
	Texte score(30, Vector2f(50.f, 5.f), "0");
	string scoreString;
	int scoreInt = 0;
	int scoreBonus = 0;
	int scoreEtBonus = 0;

	//Texte PV
	string pointsVieString = "X " + to_string(niveaux.joueur.pv);
	Texte pointsVie(30, Vector2f(WINDOWX - 50, 5), pointsVieString);

	//Texte titre
	Texte ecranTitre1(180, Vector2f(WINDOWX / 2, 250), "GALACTIC");
	Texte ecranTitre2(180, Vector2f(WINDOWX / 2, 360), "CLASH");
	Texte ecranTitre3(40, Vector2f(WINDOWX / 2, 650), "Appuyez sur START pour jouer");

	//Texte ecran score
	string ecranScoreString1;
	string ecranScoreString2;
	string ecranScoreString3;

	Texte ecranScore1(110, Vector2f(WINDOWX / 2, 200), ecranScoreString1);
	Texte ecranScore2(60, Vector2f(WINDOWX / 2, 400), ecranScoreString2);
	Texte ecranScore3(60, Vector2f(WINDOWX / 2, 500), ecranScoreString3);
	Texte ecranScore4(40, Vector2f(WINDOWX / 2, 650), "Appuyez sur START pour continuer");

	//Musique
	Music musiqueIntro;
	Music musiqueNiveau1;
	Music musiqueNiveau2;
	Music musiqueNiveau3;

	if (!musiqueIntro.openFromFile("musique/intro.ogg"))
		cout << "ERROR" << endl;
	if (!musiqueNiveau1.openFromFile("musique/niveau1.ogg"))
		cout << "ERROR" << endl;
	if (!musiqueNiveau2.openFromFile("musique/niveau2.ogg"))
		cout << "ERROR" << endl;
	if (!musiqueNiveau3.openFromFile("musique/niveau3.ogg"))
		cout << "ERROR" << endl;
	bool playMusic = true;

	//SFX
	sf::SoundBuffer buffer1;
	if (!buffer1.loadFromFile("SFX/laser.wav"))
		cout << "ERROR" << endl;
	Sound laserSFX;
	laserSFX.setBuffer(buffer1);
	laserSFX.setVolume(30);
	laserSFX.setPitch(0.7);

	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("SFX/canon.wav"))
		cout << "ERROR" << endl;
	Sound canonSFX;
	canonSFX.setVolume(50);
	canonSFX.setPitch(1.5);

	canonSFX.setBuffer(buffer2);
	
	sf::SoundBuffer buffer3;
	if (!buffer3.loadFromFile("SFX/explosion.wav"))
		cout << "ERROR" << endl;
	Sound explosionSFX;
	explosionSFX.setBuffer(buffer3);
	sf::SoundBuffer buffer4;
	if (!buffer4.loadFromFile("SFX/defeat.wav"))
		cout << "ERROR" << endl;
	Sound defeatSFX;
	defeatSFX.setBuffer(buffer4);
	sf::SoundBuffer buffer5;
	if (!buffer5.loadFromFile("SFX/bombe.wav"))
		cout << "ERROR" << endl;
	Sound bombeSFX;
	bombeSFX.setBuffer(buffer5);
	bool megabombeSFX = true;





	//BDD
	bdd.openDatabase();
	bdd.executeQuery("CREATE TABLE IF NOT EXISTS scorebdd (nom TEXT, score INT)");
	vectHighScore = bdd.getHighScore();


	//High Score





	//Boucle de jeu
	while (window.isOpen())
	{
		Time frameRate = frame.restart();


		if (sf::Joystick::isConnected(0))
		{
			//cout << "is connected" << endl;

		}
		//cout << ecranScoreString << endl;

		/*for (int i = 0; i< niveaux.ennemis.size(); i++)
			cout << "vitesse tir " << niveaux.ennemis[i].vitesseTir << endl;

		//cout << "frame rate : " << 1.f / frameRate.asMilliseconds() * 1000 << endl;
		/*cout << "shoot1 " << niveaux.shoot1 << endl;
		cout << "shoot12 " << niveaux.shoot12 << endl;
		cout << "shoot2 " << niveaux.shoot2 << endl;
		cout << "shoot3 " << niveaux.shoot3 << endl;
		cout << "fini " << niveaux.fini << endl;
		cout << "go " << niveaux.go << endl;
		cout << "bossGo " << niveaux.bossGo << endl;
		cout << "clock " << niveaux.clock1.getElapsedTime().asSeconds() << endl;*/



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

		niveaux.joueur.joueurPositionPrecedente = niveaux.joueur.sprite.getPosition(); //permet de récupérer la position du joueur avant déplacement afin de gérer les collisions avec le bord de l'écran
		niveaux.joueur.sprite.move(niveaux.joueur.deplacement().x, niveaux.joueur.deplacement().y);

		//HitBox du joueur//////////////////////////////////////////////////////////////////
		niveaux.joueur.hitBoxJoueur.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x, niveaux.joueur.sprite.getPosition().y));

		//Collision joueur/bord écran/////////////////////////////////////////////////////////////////////
		niveaux.joueur.collisionBordure(bordureGauche);
		niveaux.joueur.collisionBordure(bordureDroite);
		niveaux.joueur.collisionBordure(bordureHaut);
		niveaux.joueur.collisionBordure(bordureBas);

		//Explosion /////////////////////////////////////////////////////////////////
		explosionJoueur.explosion.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x + 1, niveaux.joueur.sprite.getPosition().y + 7));
		explosionJoueur.trigger = niveaux.joueur.boom;
		explosionJoueur.animation();
		if (niveaux.joueur.SFX == true)
		{
			defeatSFX.play();
			explosionSFX.play();
			niveaux.joueur.SFX = false;
		}
		if (megaBombeRechargee == false && megaBombeCmpt < 3)
		{
			if (megaBombExplosionsClock.getElapsedTime().asMilliseconds() > 3)
			{
				megaBombeExplosion.explosion.setPosition(Vector2f(rand() % int(WINDOWX), rand() % int(WINDOWY)));
				explosions.push_back(megaBombeExplosion);
				
			}
			if (megabombeSFX == true && jeu==JEU)
			{
				bombeSFX.play();
				megabombeSFX = false;
			}
			megaBombExplosionsClock.restart();
			
		}
		if (megaBombeCmpt >= 3)
		{
			explosions.clear();
			megabombeSFX = true;
		}
		for (int i = 0; i < explosions.size(); i++)
		{

			explosions[i].animation();
		}


		//Tir/////////////////////////////////////////////////////////////////////


		niveaux.joueur.jaugecanon();


		if (Keyboard::isKeyPressed(Keyboard::LControl) && niveaux.joueur.tirOK == true && niveaux.joueur.move == true ||
			Joystick::isButtonPressed(0, 2) && niveaux.joueur.tirOK == true && niveaux.joueur.move == true)
		{
			missile.cercle.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x - missile.cercle.getRadius(), niveaux.joueur.sprite.getPosition().y - niveaux.joueur.sprite.getTextureRect().height));
			missiles.push_back(missile);
			if(jeu==JEU)
			laserSFX.play();
			niveaux.joueur.tirOK = false;
			tempsActivationCanon.restart();

		}
		else if (Keyboard::isKeyPressed(Keyboard::LControl) && niveaux.joueur.move == true && tempsActivationCanon.getElapsedTime().asSeconds() > 0.4 ||
			Joystick::isButtonPressed(0, 2) && niveaux.joueur.move == true && tempsActivationCanon.getElapsedTime().asSeconds() > 0.4)
		{
			if (cadenceCanon.getElapsedTime().asMilliseconds() >= 30)
			{
				niveaux.joueur.canonActif = true;
				if (niveaux.joueur.valeurJaugeCanon > 0)
				{
					canon.cercle.setPosition(Vector2f(niveaux.joueur.sprite.getPosition().x - 15 + +rand() % 10, niveaux.joueur.sprite.getPosition().y - niveaux.joueur.sprite.getTextureRect().height * 3));
					missiles.push_back(canon);
					if (jeu == JEU)
					canonSFX.play();
					cadenceCanon.restart();
				}
			}
		}
		if (!Joystick::isConnected(0))
		{
			if (!Keyboard::isKeyPressed(Keyboard::LControl))
			{
				niveaux.joueur.tirOK = true;
				niveaux.joueur.canonActif = false;
			}
		}
		else
		{
			if (!Joystick::isButtonPressed(0, 2))
			{
				niveaux.joueur.tirOK = true;
				niveaux.joueur.canonActif = false;
			}
		}



		for (unsigned int i = 0; i < missiles.size(); i++)
		{

			missiles[i].cercle.move(0.f, -22.f);


			if (missiles[i].cercle.getPosition().y < -10)
			{
				missiles.erase(missiles.begin() + i);
			}
		}



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

			jeu = MISSIONACCOMPLIE;

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
				niveaux.ennemis[j].dégatsJoueur = false;

				if (niveaux.ennemis[j].SFX == true)
				{
					explosionSFX.play();
					niveaux.ennemis[j].SFX = false;
				}

			}
		}
		if (Keyboard::isKeyPressed(Keyboard::LShift) && megaBombeRechargee == true && megaBombeActive == false ||
			Joystick::isButtonPressed(0, 0) && megaBombeRechargee == true && megaBombeActive == false)
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
		if (!Joystick::isConnected(0))
		{
			if (megaBombeClock.getElapsedTime().asMilliseconds() > 400 && !Keyboard::isKeyPressed(Keyboard::LShift))
			{
				megaBombeActive = false;
				megaBombeRechargee = true;
				megaBombeCmpt = 0;
			}
		}
		else
		{
			if (megaBombeClock.getElapsedTime().asMilliseconds() > 400 && !Joystick::isButtonPressed(0, 0))
			{
				megaBombeActive = false;
				megaBombeRechargee = true;
				megaBombeCmpt = 0;
			}
		}
		//cout << "pv" << niveaux.joueur.pv  << endl;

		for (int i = 0; i < niveaux.ennemis.size(); i++)
		{
			niveaux.ennemis[i].ennemiHit();
		}

		//Collision joueur/ennemis /////////////////////////////////////////////////////////////////////


		for (unsigned int i = 0; i < niveaux.ennemis.size(); i++)
		{
			if (niveaux.ennemis[i].dégatsJoueur == true)
			{
				niveaux.joueur.collisionEnnemi(niveaux.ennemis[i]);
				pointsVie.textString = "X " + to_string(niveaux.joueur.pv);
			}

		}
		for (int j = 0; j < niveaux.vectMissileEnnemi.size(); j++)
		{
			if (niveaux.vectMissileEnnemi[j].dégatsJoueur == true)
			{
				niveaux.joueur.collisionEnnemi(niveaux.vectMissileEnnemi[j]);
				pointsVie.textString = "X " + to_string(niveaux.joueur.pv);
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
		//cout << "temps " << temps.getElapsedTime().asSeconds() << endl;


		if (elapsed.asSeconds() > 2.5)
		{
			niveaux.joueur.joueurNormalApresInvincible();
		}

		if (niveaux.joueur.pv < 0)
		{

			niveaux.clock1.restart();
			jeu = GAMEOVER;

		}

		cout << "fini " << niveaux.fini << endl;
		cout << "musique " << musiqueNiveau1.getStatus() << endl;
		//Etats du jeu et affichage ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		switch (jeu)
		{
		case TITRE:

			//musiqueIntro.play();
			window.clear();
			if (playMusic == true)
			{
				musiqueNiveau1.stop();
				musiqueNiveau2.stop();
				musiqueNiveau3.stop();

				musiqueIntro.play();
				musiqueIntro.setVolume(50);
				playMusic = false;
			}

			//REINITIALISATION DES VARIABLES DE JEU
			niveauEnCours = 0;
			scoreInt = 0;
			score.textString = "0";


			//AFFICHAGE




			window.draw(ecranTitre1.ecrireTexte());
			window.draw(ecranTitre2.ecrireTexte());
			if (tempsTitre.getElapsedTime().asSeconds() > 3)
			{
				window.draw(ecranTitre3.ecrireTexte());
				goOn = true;
			}

			ecranTitre1.text.setFillColor(Color(rouge, vert, bleu));
			ecranTitre2.text.setFillColor(Color(rouge, vert, bleu));

			//Permet de faire varier la couleur de l'écran titre
			if (temps.getElapsedTime().asMilliseconds() > 20)
			{
				bleu += 22;
				if (bleu > 150)
					bleu = 20;
				rouge += 20;
				vert += 2;


			}
			//LOGIQUE

			//On lance le jeu en appuyant sur espace (un message l'indique à l'écran)


			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true ||
				Joystick::isButtonPressed(0, 7) && goOn == true)
			{
				musiqueIntro.stop();
				playMusic = true;
				for (int i = 0; i < niveaux.ennemis.size(); i++)
					niveaux.ennemis[i].vitesseTir = 0;
				niveaux.bossGo = false;
				niveaux.go = false;
				niveaux.ennemi1.tirOk = false;
				niveaux.ennemi12.tirOk = false;
				niveaux.ennemi2.tirOk = false;
				niveaux.ennemi3.tirOk = false;
				niveaux.shoot1 = false;
				niveaux.shoot12 = false;
				niveaux.shoot2 = false;
				niveaux.shoot3 = false;
				niveaux.ennemis.clear();
				niveaux.vectMissileEnnemi.clear();
				missiles.clear();
				temps.restart();
				niveaux.clock1.restart();
				niveauEnCours = 1;
				jeu = JEU;
			}


			break;

		case JEU:

			//LOGIQUE
			//Permet de faire varier la couleur du fond en fonction du niveau
			switch (niveauEnCours)
			{
			case 1:
				window.clear(Color(0, 10, 20));
				if (playMusic == true)
				{
					musiqueNiveau1.play();
					musiqueNiveau1.setVolume(30);
					musiqueNiveau1.setLoop(true);
					playMusic = false;
				}

				break;
			case 2:
				window.clear(Color(30, 0, 50));
				if (playMusic == true)
				{
					musiqueNiveau2.play();
					musiqueNiveau2.setVolume(30);
					musiqueNiveau2.setLoop(true);
					playMusic = false;
				}

				break;
			case 3:
				window.clear(Color(25, 25, 50));
				if (playMusic == true)
				{
					musiqueNiveau3.play();
					musiqueNiveau3.setVolume(30);
					musiqueNiveau3.setLoop(true);
					playMusic = false;
				}
				break;
			default:
				window.clear(Color(0, 20, 30));
				break;
			}

			//AFFICHAGE

			//Affichage du fond étoilé
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
			afficherVector(explosions, window);

			//Affichage des textes
			window.draw(score.ecrireTexte());
			window.draw(pointsVie.ecrireTexte());
			window.draw(niveaux.joueur.formeJaugeCanon);
			window.draw(niveaux.joueur.contourJaugeCanon);


			break;

		case MISSIONACCOMPLIE:
			window.clear();
			ecranScoreString1 = "MISSION " + to_string(niveauEnCours) + " ACCOMPLIE";
			ecranScore1.textString = ecranScoreString1;
			switch (niveauEnCours)
			{
			case 1:
				scoreBonus = 10000;

				break;
			case 2:
				scoreBonus = 15000;
				break;
			case 3:
				scoreBonus = 20000;
				break;
			case 4:
				scoreBonus = 50000;
				break;
			}
			ecranScoreString2 = "BONUS : " + to_string(scoreBonus);
			ecranScore2.textString = ecranScoreString2;
			scoreEtBonus = scoreInt + scoreBonus;
			scoreString = to_string(scoreEtBonus);
			ecranScoreString3 = "VOUS AVEZ " + scoreString + " POINTS";
			ecranScore3.textString = ecranScoreString3;


			window.draw(ecranScore1.ecrireTexte());
			window.draw(ecranScore2.ecrireTexte());
			window.draw(ecranScore3.ecrireTexte());
			window.draw(ecranScore4.ecrireTexte());


			niveaux.fini = false;//

			niveaux.joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
			goOn = false;

			//Permet de bloquer l'écran "GAGNE" pendant une certaine durée
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(ecranScore3.ecrireTexte());
				goOn = true;
			}

			niveaux.ennemis.clear();
			missiles.clear();
			niveaux.vectMissileEnnemi.clear();

			//
			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true ||
				Joystick::isButtonPressed(0, 7) && goOn == true)
			{

				musiqueNiveau1.stop();
				musiqueNiveau2.stop();
				musiqueNiveau3.stop();

				playMusic = true;
				scoreInt = scoreEtBonus;
				score.textString = to_string(scoreInt);
				niveaux.clock1.restart();
				niveaux.bossGo = false;
				niveaux.go = false;
				niveauEnCours++;
				jeu = JEU;
			}

			break;

		case GAMEOVER:
			window.clear();
			
				musiqueNiveau1.stop();
				musiqueNiveau2.stop();
				musiqueNiveau3.stop();
				
			

			window.draw(textePerdu.ecrireTexte());
			window.draw(entrezVotreNom.ecrireTexte());

			nomDuJoueur = highScore.entrerNom(window);
			niveauEnCours = 0;
			niveaux.joueur.pv = PVORIGINE;
			pointsVieString = "X " + to_string(niveaux.joueur.pv);
			pointsVie.textString = pointsVieString;


			niveaux.joueur.sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
			goOn = false;

			//Permet de bloquer l'écran "PERDU" pendant une certaine durée
			if (elapsed.asSeconds() > 1.5)
			{
				window.draw(texteAppuyezEspace.ecrireTexte());
				goOn = true;
			}

			niveaux.vectMissileEnnemi.clear();
			niveaux.ennemis.clear();
			missiles.clear();

			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true ||
				Joystick::isButtonPressed(0, 7) && goOn == true)
			{

				bdd.insertScore(nomDuJoueur, scoreInt);
				window.clear();
				///////////////////////////////////////////////////
				vectHighScore = bdd.getHighScore();


				///////////////////////////////////////////////////
				goOn = false;
				temps.restart();
				tempsTitre.restart();
				jeu = HISCORE;

			}

			break;

		case HISCORE:
			window.clear();
			niveauEnCours = 0;
			highScore.afficherHighScore(vectHighScore, window);
			if (elapsed.asSeconds() > 1.5)
			{

				goOn = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::Space) && goOn == true ||
				Joystick::isButtonPressed(0, 7) && goOn == true)
			{
				playMusic = true;
				goOn = false;
				temps.restart();
				tempsTitre.restart();
				jeu = TITRE;
			}

			break;

		}
		window.display();
	}


	bdd.closeDatabase();
}

void Game::affichage()
{

}
