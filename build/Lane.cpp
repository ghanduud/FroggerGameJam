#include "Lane.h"

Lane::Lane(LaneType type,sf::Vector2f size)
{
	laneType = type;
	laneTile.setSize(size);
	switch (type)
	{
	case resting:
		laneTile.setFillColor(sf::Color::Green);
		break;
	case road:
		laneTile.setFillColor(sf::Color::Color(60,60,60,255));
		break;
	case water:
		laneTile.setFillColor(sf::Color::Blue);
		break;
	default:
		break;
	}
}

void Lane::render(sf::RenderWindow& window,int index)
{
	laneTile.setPosition(sf::Vector2f(0, (10 - index) * laneTile.getSize().y));
	window.draw(laneTile);
}