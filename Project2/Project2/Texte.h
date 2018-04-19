#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Texte /// Classe de création des texte SFML à afficher à l'écran
{
public:
	Texte(int tailleTexte, sf::Vector2f position, std::string textString); /// Constructeur de l'objet Texte
	~Texte();

	sf::Text ecrireTexte(); /// Fonction utilisée dans une sf::Window pour afficher le texte

	sf::Text text; /// Objet Text
	sf::Font font; /// Objet Font
	std::string textString; /// string contenant le texte à afficher
	sf::Vector2f position; /// position du texte à l'écran
	int tailleTexte; /// taille du texte



};

