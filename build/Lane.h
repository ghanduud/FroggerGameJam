#pragma once
#include "MovingPlatform.h"

enum LaneType
{
	resting,
	road,
	water
};

class Lane
{
public:
	LaneType laneType;
	std::vector<MovingPlatform> movingPlatforms;
	sf::RectangleShape laneTile;
	Lane(LaneType type, sf::Vector2f size);
	void render(sf::RenderWindow &window,int index);
};

