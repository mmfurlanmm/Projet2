#include "Etoiles.h"

using namespace sf;
using namespace std;



Etoiles::Etoiles(Color couleur, float vitesse)
{
	forme.setFillColor(couleur);
	forme.setSize(Vector2f( 4.f, 4.f ));
	this->vitesse = vitesse;
}


Etoiles::~Etoiles()
{
}
