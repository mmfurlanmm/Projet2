#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

class Texte /// Classe de cr�ation des texte SFML � afficher � l'�cran
{
public:
	Texte(int tailleTexte, sf::Vector2f position, std::string textString); /// Constructeur de l'objet Texte
	~Texte();

	sf::Text ecrireTexte(); /// Fonction utilis�e dans une sf::Window pour afficher le texte

	sf::Text text; /// Objet Text
	sf::Font font; /// Objet Font
	std::string textString; /// string contenant le texte � afficher
	sf::Vector2f position; /// position du texte � l'�cran
	int tailleTexte; /// taille du texte



};

