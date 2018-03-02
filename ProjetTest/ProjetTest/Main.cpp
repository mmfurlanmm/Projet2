#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace sf;
using namespace std;



int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(640, 480), "Shoot or die");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	bool jeu = true;
	
	//joueur
	RectangleShape joueur;
	joueur.setFillColor(Color::White);
	joueur.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y - 5));
	joueur.setSize(Vector2f(20.f, 30.f));
	joueur.setOrigin(Vector2f(joueur.getSize().x / 2, joueur.getSize().y));
	bool joueurBougeGauche = true;
	bool joueurBougeDroite = true;
	int pv = 3;
	float vitesse = 7;


	//Missiles
	RectangleShape missile;
	missile.setSize(Vector2f(5.f, 10.f));
	missile.setFillColor(Color::Cyan);
	vector<RectangleShape> missiles;
	missiles.push_back(missile);
	bool tirOK = true;

	//ennemis
	RectangleShape ennemi;
	ennemi.setSize(Vector2f(40.f, 10.f));
	ennemi.setFillColor(Color::Red);
	vector<RectangleShape> ennemis;
	ennemis.push_back(ennemi);
	int ennemiSpawn = 0;



	//bords de l'écran
	RectangleShape bordureGauche;
	bordureGauche.setPosition(0, 0);
	bordureGauche.setSize(Vector2f(1.f, window.getSize().y));
	bordureGauche.setFillColor(Color::Transparent);

	RectangleShape bordureDroite;
	bordureDroite.setPosition(window.getSize().x, 0);
	bordureDroite.setSize(Vector2f(1.f, window.getSize().y));
	bordureDroite.setFillColor(Color::Transparent);

	//Texte Perdu
	Text text;
	Font font;
	if (!font.loadFromFile("Nintendo-DS-BIOS.ttf"))
	{
		cout << "erreur" << endl;
	}

	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	int texteDuree = 100;
	text.setString("Perdu !");
	text.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 - text.getCharacterSize());

	//Score
	Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	score.setFillColor(sf::Color::White);
	score.setStyle(sf::Text::Bold);
	score.setPosition(5, 5);
	score.setString("0");
	int scoreInt = 0;
	string scoreString;
	stringstream ss;




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

		while (jeu == true)
		{
			//Event event;
			//Gestion de la saisie utilisateur
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed || Keyboard().isKeyPressed(Keyboard::Escape))
				{
					window.close();
				}
			}

			//Déplacement joueur

			if (Keyboard().isKeyPressed(Keyboard::Left) && joueurBougeGauche == true)
			{
				joueur.move(-vitesse, 0.f);
				joueurBougeDroite = true;

			}

			if (Keyboard().isKeyPressed(Keyboard::Right) && joueurBougeDroite == true)
			{
				joueur.move(vitesse, 0.f);
				joueurBougeGauche = true;
			}


			//Tir

			if (Keyboard().isKeyPressed(Keyboard::Space) && tirOK == true)
			{
				missile.setPosition(Vector2f(joueur.getPosition().x - missile.getSize().x / 2, joueur.getPosition().y - joueur.getSize().y));
				missiles.push_back(missile);
				tirOK = false;
			}
			else if (!Keyboard().isKeyPressed(Keyboard::Space))
			{
				tirOK = true;
			}

			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				missiles[i].move(0.f, -10.f);

				if (missiles[i].getPosition().y < 0)
				{
					missiles.erase(missiles.begin() + i);
				}
			}

			//Déplacement ennemis

			if (ennemiSpawn < 20)
				ennemiSpawn++;

			if (ennemiSpawn >= 20)
			{
				ennemi.setPosition(rand() % int(window.getSize().x - ennemi.getSize().x), 0);
				ennemis.push_back(ennemi);

				ennemiSpawn = 0;
			}

			for (unsigned int i = 0; i < ennemis.size(); i++)
			{
				ennemis[i].move(0.f, 8);

				if (ennemis[i].getPosition().y > window.getSize().y)
				{
					ennemis.erase(ennemis.begin() + i);
				}

			}

			//Collisions ennemis/missiles
			
			for (unsigned i = 0; i < missiles.size(); i++)
			{
				for (unsigned int j = 0; j < ennemis.size(); j++)
				{
					if (missiles[i].getGlobalBounds().intersects(ennemis[j].getGlobalBounds()))
					{
						missiles.erase(missiles.begin() + i);
						ennemis.erase(ennemis.begin() + j);
						scoreInt = scoreInt +100;
						scoreString = to_string(scoreInt);
						score.setString(scoreString);
						
						break;

					}
				}
			}

			//Collision joueur/bord écran
			if (joueur.getGlobalBounds().intersects(bordureGauche.getGlobalBounds()))
			{
				joueurBougeGauche = false;
			}

			if (joueur.getGlobalBounds().intersects(bordureDroite.getGlobalBounds()))
			{
				joueurBougeDroite = false;
			}

			//Collision joueur/ennemis
			for (unsigned int i = 0; i < ennemis.size(); i++)
			{
				if (joueur.getGlobalBounds().intersects(ennemis[i].getGlobalBounds()))
				{
					jeu = false;

				}
			}
			//Affichage
			window.clear();

			window.draw(joueur);
			window.draw(bordureGauche);
			window.draw(bordureDroite);
			window.draw(score);

			//Boucle d'affichage des ennemis
			for (unsigned int i = 0; i < ennemis.size(); i++)
			{
				window.draw(ennemis[i]);
			}

			//Boucle d'affichage des missiles
			for (unsigned int i = 0; i < missiles.size(); i++)
			{
				window.draw(missiles[i]);
			}

			window.display();

		}


		window.clear();

		window.draw(text);

		window.display();
	}
	return 0;
}