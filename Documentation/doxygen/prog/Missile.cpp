#include "Missile.h"
using namespace sf;
using namespace std;



Missile::Missile()
{
	
	cercle.setRadius(9);
	cercle.setFillColor(Color::White);
	cercle.setOutlineThickness(-3);
	cercle.setOutlineColor(Color::Cyan);
	
}


Missile::~Missile()
{
}


