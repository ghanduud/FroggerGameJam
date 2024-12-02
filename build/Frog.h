#pragma once

#include <SFML/Graphics.hpp>

#include "AABBCollider.h"

enum Direction {
	NONE, UP, DOWN, LEFT, RIGHT
};


class Frog
{
public:
	// Attributes
	sf::Vector2f frogPosition;
	float frogSize;
	float frogVelocity;
	bool isAlive;
	bool isJumping;
	Direction frogDirection;

	sf::RectangleShape frogShapeTest; // for testing on

	sf::Sprite frogSprite; // the used sprite
	sf::Sprite frogJumpingSprite;
	sf::Sprite frogStandingSprite;


	// Methods

	Frog();
	Frog(sf::Vector2f Position, float laneHeight);
	
	bool isDead();
	void death();
	bool isOutOfScreenBounds(int screenWidth, int screenHeight);
	void update(float deltaTime, Direction dir);
	void render(sf::RenderWindow& window);
	void stretchingLegs(float deltaTime);

};

