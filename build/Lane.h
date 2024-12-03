#pragma once
#include "MovingPlatform.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "TextureLoader.h"

enum LaneType
{
	resting,
	road,
	water,
	END,
	BLOCK,
};

class Lane
{
public:
	LaneType laneType;
	std::vector<MovingPlatform> movingPlatforms;
	sf::RectangleShape laneTile;
	sf::Sprite landSprit;
	//sf::Texture* landTexture;

	Lane(LaneType type, sf::Vector2f size,TextureLoader& textureLoader, bool isInverted);
	void render(sf::RenderWindow &window,int index);
};

