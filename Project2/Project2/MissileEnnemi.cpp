#include "MissileEnnemi.h"
using namespace sf;
using namespace std;



MissileEnnemi::MissileEnnemi()
{
	cercle.setRadius(9);
	cercle.setPointCount(8);
	cercle.setOutlineThickness(-4);

	cout << "clock" << clock.getElapsedTime().asSeconds() << endl;
	cercle.setFillColor(Color::White);
	cercle.setOutlineColor(Color::Magenta);
	
	
}


MissileEnnemi::~MissileEnnemi()
{
}


