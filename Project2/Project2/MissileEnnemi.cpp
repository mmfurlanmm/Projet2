#include "MissileEnnemi.h"
using namespace sf;
using namespace std;



MissileEnnemi::MissileEnnemi()
{
	cercle.setRadius(10);
	cercle.setPointCount(10);
	cercle.setOutlineThickness(-4);

	
	cercle.setFillColor(Color::White);
	cercle.setOutlineColor(Color::Magenta);
	
	
	
}


MissileEnnemi::~MissileEnnemi()
{
}


