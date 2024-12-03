#pragma once
#include "MovingPlatform.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "TextureLoader.h"
#include "Frog.h"

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
	Direction laneDirection;
	//sf::Texture* landTexture;

	Lane(LaneType type, sf::Vector2f size,TextureLoader& textureLoader, bool isInverted);
	void render(sf::RenderWindow &window,int index);
	void setSpritToLane(sf::Texture& texture, sf::Vector2f size, bool isWater, sf::Texture& landTexture);
};

