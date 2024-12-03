#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "AABBCollider.h"
#include "TextureLoader.h"

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

	float laneSpeed = 0;

	sf::RectangleShape frogShapeTest; // for testing on

	

	sf::Sprite frogSprite; // the used sprite


	AABBCollider frogCollider;

	// Methods

	Frog();
	Frog(sf::Vector2f Position, float laneHeight, TextureLoader& textureLoader, sf::Vector2f size);
	
	//void getSprites();
	bool isDead();
	void death();
	bool isOutOfScreenBounds(sf::Vector2f newPosition, int screenWidth, int screenHeight);
	void update(float deltaTime, Direction dir);
	void render(sf::RenderWindow& window);
	void stretchingLegs(float deltaTime);
	void frogOnWater(float speed, float dt);

};

