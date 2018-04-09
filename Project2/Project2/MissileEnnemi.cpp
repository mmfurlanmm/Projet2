#include "MissileEnnemi.h"
using namespace sf;
using namespace std;



MissileEnnemi::MissileEnnemi()
{
	cercle.setRadius(12);
	cercle.setPointCount(10);
	cercle.setOutlineThickness(-5);

	
	cercle.setFillColor(Color::White);
	cercle.setOutlineColor(Color::Magenta);
	
	
}


MissileEnnemi::~MissileEnnemi()
{
}


