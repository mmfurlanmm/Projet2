#include "MissileEnnemi.h"
using namespace sf;
using namespace std;



MissileEnnemi::MissileEnnemi()
{
	forme.setSize(Vector2f(10.f, 10.f));

	cout << "clock" << clock.getElapsedTime().asSeconds() << endl;
	forme.setFillColor(Color::Magenta);
	
	
}


MissileEnnemi::~MissileEnnemi()
{
}


