#include "Missile.h"
using namespace sf;
using namespace std;



Missile::Missile()
{
	missile.setSize(Vector2f(7.f, 10.f));
	missile.setFillColor(Color::Cyan);
}


Missile::~Missile()
{
}
