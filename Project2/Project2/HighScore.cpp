#include "HighScore.h"
using namespace sf;
using namespace std;



HighScore::HighScore()
{
}


HighScore::~HighScore()
{
}

void HighScore::afficherHighScore(std::vector<enregistrementBDD*>* highScore, sf::RenderWindow &window)
{

	string strligne1 = "1.      " + (*highScore)[0]->nom + "      " + to_string((*highScore)[0]->score);
	Texte ligne1(60, Vector2f(WINDOWX / 2, 100), strligne1);
	ligne1.text.setFillColor(Color(255, 0, 0));
	

	string strligne2 = "2.      " + (*highScore)[1]->nom + "      " + to_string((*highScore)[1]->score);
	Texte ligne2(60, Vector2f(WINDOWX / 2, 200), strligne2);
	ligne2.text.setFillColor(Color(255, 127, 0));

	string strligne3 = "3.      " + (*highScore)[2]->nom + "      " + to_string((*highScore)[2]->score);
	Texte ligne3(60, Vector2f(WINDOWX / 2, 300), strligne3);
	ligne3.text.setFillColor(Color(255, 255, 0));

	string strligne4 = "4.      " + (*highScore)[3]->nom + "      " + to_string((*highScore)[3]->score);
	Texte ligne4(60, Vector2f(WINDOWX / 2, 400), strligne4);
	ligne4.text.setFillColor(Color(0, 255, 0));

	string strligne5 = "5.      " + (*highScore)[4]->nom + "      " + to_string((*highScore)[4]->score);
	Texte ligne5(60, Vector2f(WINDOWX / 2, 500), strligne5);
	ligne5.text.setFillColor(Color(0, 0, 255));

	string strligne6 = "6.      " + (*highScore)[5]->nom + "      " + to_string((*highScore)[5]->score);
	Texte ligne6(60, Vector2f(WINDOWX / 2, 600), strligne6);
	ligne6.text.setFillColor(Color(148, 0, 211));

	window.draw(ligne1.ecrireTexte());
	window.draw(ligne2.ecrireTexte());
	window.draw(ligne3.ecrireTexte());
	window.draw(ligne4.ecrireTexte());
	window.draw(ligne5.ecrireTexte());
	window.draw(ligne6.ecrireTexte());



}


string HighScore::entrerNom(sf::RenderWindow & window)
{
	string premiereLettre = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string deuxiemeLettre = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string troisiemeLettre = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string repere = "_";
	string nom;
	nom.push_back(premiereLettre[i]);
	nom.push_back(deuxiemeLettre[j]);
	nom.push_back(troisiemeLettre[k]);

	


	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	//ON CHANGE DE LETTRE AVEC GAUCHE ET DROITE
	if (x > 1 && goX == true)
	{
		lettre++;
		repereX += 100;
		goX = false;
		if (lettre > 2)
			lettre = 0;
		if (repereX > 450)
			repereX = 250;
	}
	else if (x < -1 && goX == true)
	{
		lettre--;
		repereX -= 100;
		goX = false;
		if (lettre < 0)
			lettre = 2;
		if (repereX <250)
			repereX = 450;
	}
	else if (x<1 && x>-1)
		goX = true;


	if (y < -1 && goY == true)
	{
		if (lettre == 0)
			i++;
		if (lettre == 1)
			j++;
		if (lettre == 2)
			k++;

		goY = false;
		if (i > 26)
			i = 0;
		if (j > 26)
			j = 0;
		if (k > 26)
			k = 0;
	}
	else if (y > 1 && goY == true)
	{
		if (lettre == 0)
			i--;
		if (lettre == 1)
			j--;
		if (lettre == 2)
			k--;
		goY = false;
		if (i < 0)
			i = 26;
		if (j < 0)
			j = 26;
		if (k < 0)
			k = 26;
	}
	else if (y<1 && y>-1)
		goY = true;
	
	string strPremiereLettre;
	strPremiereLettre.push_back(premiereLettre[i]);
	string strDeuxiemeLettre;
	strDeuxiemeLettre.push_back(deuxiemeLettre[j]);
	string strTroisiemeLettre;
	strTroisiemeLettre.push_back(troisiemeLettre[k]);
	Texte txtPremiereLettre(100, Vector2f(250, WINDOWY / 2), strPremiereLettre);
	Texte txtDeuxiemeLettre(100, Vector2f(350, WINDOWY / 2), strDeuxiemeLettre);
	Texte txtTroisiemeLettre(100, Vector2f(450, WINDOWY / 2), strTroisiemeLettre);
	Texte txtRepere(100, Vector2f(repereX, WINDOWY / 2), repere);

	window.draw(txtPremiereLettre.ecrireTexte());
	window.draw(txtDeuxiemeLettre.ecrireTexte());
	window.draw(txtTroisiemeLettre.ecrireTexte());
	window.draw(txtRepere.ecrireTexte());


	return nom;

	//string nom = premiereLettre[i] + deuxiemeLettre[i] + troisiemeLettre[i];
	cout << nom << endl;
}
