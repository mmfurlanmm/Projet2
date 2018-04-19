#pragma once
#include "Ennemi.h"
class EnnemiBoss :	public Ennemi
{
public:
	EnnemiBoss();
	~EnnemiBoss();
	sf::Texture texture2; /// EnnemiBoss, héritant de la classe Ennemi, dispose d'une texture supplémentaire pour le deuxième boss du jeu (objet bossFinal, voir la classe niveaux)
};

