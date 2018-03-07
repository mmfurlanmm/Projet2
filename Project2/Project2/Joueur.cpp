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
	spriteJoueur.setTexture(texture);
	spriteJoueur.setTextureRect(IntRect(0, 0, 16, 16));
	spriteJoueur.setScale(3, 3);
	spriteJoueur.setOrigin(spriteJoueur.getTextureRect().width / 2, spriteJoueur.getTextureRect().height);
	

	//Gestion de la hitbox du joueur
	hitBoxJoueur.setFillColor(Color::Transparent);
	hitBoxJoueur.setSize(Vector2f(22, 35));
	hitBoxJoueur.setOrigin(Vector2f(hitBoxJoueur.getSize().x / 2, hitBoxJoueur.getSize().y));
	
	//Caractéristiques de base du joueur
	vitesse = 8;
	pv = 3;
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

	if (Keyboard().isKeyPressed(Keyboard::Left)&&move==true)
	{
		px = -vitesse;
		spriteJoueur.setTextureRect(IntRect(0, 33, 16, 16));
	}
	else if (!Keyboard().isKeyPressed(Keyboard::Left))
	{
		spriteJoueur.setTextureRect(IntRect(0, 0, 16, 16));
	}

	if (Keyboard().isKeyPressed(Keyboard::Right) && move == true)
	{
		px = vitesse;
		spriteJoueur.setTextureRect(IntRect(34, 17, 16, 16));
	}
	
	if (Keyboard().isKeyPressed(Keyboard::Up) && move == true)
	{

		py = -vitesse;
	}

	if (Keyboard().isKeyPressed(Keyboard::Down) && move == true)
	{

		py = vitesse;
	}

	return Vector2f(px, py);
}

void Joueur::collisionEnnemi(Ennemi ennemi)
{
	if (hitBoxJoueur.getGlobalBounds().intersects(ennemi.spriteEnnemi.getGlobalBounds()) && invincible == false)
	{
		
		tempsRestart = true;
		move = false;
		spriteJoueur.setColor(Color(0,0,0,0));
		boom = true;
		
		invincible = true;
		pv--;
		
	}
}
void Joueur::collisionBordure(Bordure bordure)
{
	
	if (spriteJoueur.getGlobalBounds().intersects(bordure.forme.getGlobalBounds()))
	{
		spriteJoueur.setPosition(joueurPositionPrecedente);
	}
	
}
