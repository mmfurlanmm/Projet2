#pragma once
#include "Ennemi.h"
class EnnemiBoss :	public Ennemi
{
public:
	EnnemiBoss();
	~EnnemiBoss();
	sf::Texture texture2; /// EnnemiBoss, h�ritant de la classe Ennemi, dispose d'une texture suppl�mentaire pour le deuxi�me boss du jeu (objet bossFinal, voir la classe niveaux)
};

