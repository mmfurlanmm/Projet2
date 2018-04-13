#include "Joueur.h"
#include <stdlib.h>


using namespace sf;
using namespace std;



Joueur::Joueur()
{
	//Mise en place du sprite du joueur


	if (!texture.loadFromFile("Images/joueur.png"))
	{
		cout << "erreur" << endl;
		system("pause");
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.setScale(3, 3);
	sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height);




	//Gestion de la hitbox du joueur
	hitBoxJoueur.setFillColor(Color::Transparent);
	hitBoxJoueur.setSize(Vector2f(6, 6));
	hitBoxJoueur.setOrigin(Vector2f(hitBoxJoueur.getSize().x / 2, hitBoxJoueur.getSize().y+16));

	//Caractéristiques de base du joueur
	vitesse = 6;
	pv = PVORIGINE;
	invincible = false;
	move = true;
	tempsRestart = false;
}


Joueur::~Joueur()
{
}

Vector2f Joueur::deplacement()
{


	float px = 0;
	float py = 0;
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X)/100;
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y)/100;


	if (clock.getElapsedTime().asMilliseconds() > 45)
	{
		i += 17;
		if (i > 49)
			i = 0;

		clock.restart();
	}

	if (Keyboard::isKeyPressed(Keyboard::LAlt) || Joystick::isButtonPressed(0, 5))
	{
		vitesse = 3;
	}
	else
		vitesse = 6;

	if (!Joystick::isConnected(0))
	{


		if (Keyboard().isKeyPressed(Keyboard::Left) && move == true)
		{
			px = -vitesse;
			sprite.setTextureRect(IntRect(i, 33, 16, 16));
		}
		else if (!Keyboard().isKeyPressed(Keyboard::Left))
		{
			sprite.setTextureRect(IntRect(i, 0, 16, 16));
		}

		if (Keyboard().isKeyPressed(Keyboard::Right) && move == true)
		{
			px = vitesse;
			sprite.setTextureRect(IntRect(i, 17, 16, 16));
		}

		if (Keyboard().isKeyPressed(Keyboard::Up) && move == true)
		{

			py = -vitesse;
		}

		if (Keyboard().isKeyPressed(Keyboard::Down) && move == true)
		{

			py = vitesse;
		}
	}
	else
	{
		if (move == true)
		{
			px = x*vitesse;
			py = y*vitesse;
			if(px<-1)
				sprite.setTextureRect(IntRect(i, 33, 16, 16));
			else if (px>1)
				sprite.setTextureRect(IntRect(i, 17, 16, 16));
			else
				sprite.setTextureRect(IntRect(i, 0, 16, 16));

		}
	}
	
	return Vector2f(px, py);
}



void Joueur::collisionEnnemi(Ennemi ennemi)
{
	if (hitBoxJoueur.getGlobalBounds().intersects(ennemi.sprite.getGlobalBounds()) && invincible == false ||
		hitBoxJoueur.getGlobalBounds().intersects(ennemi.forme.getGlobalBounds()) && invincible == false ||
		hitBoxJoueur.getGlobalBounds().intersects(ennemi.cercle.getGlobalBounds()) && invincible == false)
	{

		tempsRestart = true;
		move = false;
		sprite.setColor(Color(0, 0, 0, 0));
		boom = true;

		invincible = true;
		pv--;

	}
}

void Joueur::joueurRepopInvincible(Clock clock)
{


	//out << "explosion clock : " << clock.getElapsedTime().asMilliseconds() << endl;
	sprite.setColor(Color(255, 55, 55, 80));


	boom = false;

	sprite.setPosition(POSITION_D_ORIGINE_JOUEUR);
	move = true;
	clock.restart();

}

void Joueur::joueurNormalApresInvincible()
{
	sprite.setColor(Color(255, 255, 255, 255));
	invincible = false;
}

void Joueur::jaugecanon()
{
	if (canonActif == true)
	{
		valeurJaugeCanon -= 1.1;
		if (valeurJaugeCanon <= 0)
			valeurJaugeCanon = 0;
	}
	else
	{
		valeurJaugeCanon += 0.2;
		if (valeurJaugeCanon >= 100)
			valeurJaugeCanon = 100;
	}
	formeJaugeCanon.setSize(Vector2f(valeurJaugeCanon, 15));
	contourJaugeCanon.setSize(Vector2f(100, 15));
	formeJaugeCanon.setPosition(580, WINDOWY-30);
	contourJaugeCanon.setPosition(580, WINDOWY - 30);
	
	if(valeurJaugeCanon>60)
	formeJaugeCanon.setFillColor(Color::Yellow);
	else if (valeurJaugeCanon<30)
		formeJaugeCanon.setFillColor(Color::Red);
	else
		formeJaugeCanon.setFillColor(Color(255,125,0));

	contourJaugeCanon.setFillColor(Color::Transparent);
	contourJaugeCanon.setOutlineThickness(-3);
	contourJaugeCanon.setOutlineColor(Color::White);




}

void Joueur::collisionBordure(Bordure bordure)
{

	if (sprite.getGlobalBounds().intersects(bordure.forme.getGlobalBounds()))
	{
		sprite.setPosition(joueurPositionPrecedente);
	}

}


