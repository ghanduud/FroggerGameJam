#pragma once
#include "Frog.h"

#include <iostream>
#include <vector>
#include "Lane.h"
#include "Frog.h"
#include "MovingPlatform.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "TextureLoader.h"


class Level
{
public:
	Frog frog;
	std::vector <Lane> lanes;
	int score = 0;
	int start = 11;

	bool isGameOver = false;
	float gameOverTimer = 0.0f;

	Level(TextureLoader textureLoader);

	void update(float dt, Direction direction);
	void renderMap(int sizeOfLanesInWindow, sf::RenderWindow& window);
	void resetLevel();
};