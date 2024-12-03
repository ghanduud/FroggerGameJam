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
	sf::Sprite underlaySprit;

	float laneSpeed;
	Direction laneDirection;
	float totalsize;
	//sf::Texture* landTexture;

	Lane(LaneType type, sf::Vector2f size, TextureLoader& textureLoader, bool isInverted, float speed);
	void render(sf::RenderWindow &window,int index);
	void renderObsticals(sf::RenderWindow &window);
	void setSpritToLane(sf::Texture& texture, sf::Vector2f size, bool isWater, sf::Texture& landTexture);
	sf::RectangleShape setObsticalShape(int number);
	void update(float deltaTime,int start,int index);
};

