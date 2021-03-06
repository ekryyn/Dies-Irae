#include "Canon.h"
#include "Const.h"

Canon::Canon(sf::Color c) :
		power(0.5f),
		color(c)
{
	make();
}

void Canon::rotate(int offset)
{
	drawable.SetRotation(drawable.GetRotation()+offset);
}

void Canon::make()
{
	sf::Shape n;

	n.SetPosition(drawable.GetPosition());
	n.SetRotation(drawable.GetRotation());

	n.AddPoint(0, -4.f/SCALE, sf::Color(),color);
	n.AddPoint((8+power*40.f)/SCALE, -4.f/SCALE, sf::Color(), color);

	n.AddPoint(((8+power*40.f)+10.f)/SCALE, 0/SCALE, sf::Color(), color);

	n.AddPoint((8+power*40.f)/SCALE, 4.f/SCALE, sf::Color(), color);
	n.AddPoint(0, 4.f/SCALE, sf::Color(), color);

	n.EnableFill(false);
	n.SetOutlineWidth(-1.f/SCALE);

	drawable = n;
}

void Canon::changePower(float offset)
{
	if(power + offset > 0 && power + offset < 2.35f)
	{
		power += offset;
		make();
	}
}

float Canon::getPower()
{
	return power;
}

sf::Shape* Canon::getDrawable()
{
	return &drawable;
}
