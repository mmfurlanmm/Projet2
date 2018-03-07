#include "Texte.h"
using namespace sf;
using namespace std;



Texte::Texte(int tailleTexte, Vector2f position, string textString)
{
	this->tailleTexte = tailleTexte;
	this->position = position;
	this->textString = textString;

	if (!font.loadFromFile("Nintendo-DS-BIOS.ttf"))
	{
		cout << "erreur" << endl;
	}
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	
	

	

}


Texte::~Texte()
{
}

Text Texte::ecrireTexte()
{
	text.setCharacterSize(tailleTexte);
	text.setString(textString);
	text.setPosition(position);

	return text;

}
