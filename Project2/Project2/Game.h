#pragma once
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
#include "Explosion.h"
#include "Entite.h"

enum { JEU, GAMEOVER };//Gestion des �vennements du jeu

class Game
{
public:
	Game();
	~Game();
	void jeu();
};

