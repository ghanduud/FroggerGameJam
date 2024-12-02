#include "Frog.h"

Frog::Frog()
{
}

Frog::Frog(sf::Vector2f Position, float laneHeight)
{

	// set the frog to the middle of the 5th lane
	this->frogPosition = Position;
	this->frogSize = laneHeight;

	this->frogVelocity = 1.f;

	this->isAlive = true;
	this->isJumping = false;
	this->frogDirection = UP;

	// testing frog
	this->frogShapeTest.setFillColor(sf::Color::Green);
	this->frogShapeTest.setOrigin(laneHeight, laneHeight);
	this->frogShapeTest.setPosition(Position);
	this->frogShapeTest.setSize(sf::Vector2f(laneHeight, laneHeight));
	this->frogShapeTest.setRotation(270.f);


	//sf::Sprite frogSprite; // the used sprite
	//sf::Sprite frogJumpingSprite;
	//sf::Sprite frogStandingSprite;
}

bool Frog::isDead()
{
	return (!isAlive);
}

bool Frog::isOutOfScreenBounds(int screenWidth, int screenHeight)
{
	if ((this->frogPosition.x - (0.5 * this->frogSize) <= 0) || // left bound
		(this->frogPosition.x + (0.5 * this->frogSize) >= screenWidth) || // right bound
		(this->frogPosition.y - (0.5 * this->frogSize) <= 0) || // upper bound not possible
		(this->frogPosition.y + (0.5 * this->frogSize) >= screenHeight)) // lower bound not possible
	{
		return true;
	}

	return false;
}

void Frog::render(sf::RenderWindow window)
{
	window.draw(this->frogShapeTest);
}

void Frog::update(float deltaTime, Direction Dir)
{
	// if the frog doesn't move, get out!
	if (Dir == Direction::NONE) {
		return;
	}

	if (Dir == Direction::UP) 
	{
		//this->frogPosition.y -= deltaTime * frogVelocity;

		this->frogDirection = UP;
		
		if (this->frogShapeTest.getRotation() != 270)
			this->frogShapeTest.setRotation(270);

	}
	if (Dir == Direction::DOWN) 
	{
		//this->frogPosition.y += deltaTime * frogVelocity;

		this->frogDirection = DOWN;

		if (this->frogShapeTest.getRotation() != 90)
			this->frogShapeTest.setRotation(90);

	}
	if (Dir == Direction::LEFT) 
	{
		this->frogPosition.x -= deltaTime * frogVelocity;

		this->frogDirection = LEFT;

		if (this->frogShapeTest.getRotation() != 180)
			this->frogShapeTest.setRotation(180);

	}
	if (Dir == Direction::RIGHT) 
	{
		this->frogPosition.x += deltaTime * frogVelocity;

		this->frogDirection = RIGHT;

		if (this->frogShapeTest.getRotation() != 0)
			this->frogShapeTest.setRotation(0);

	}

	this->frogShapeTest.setPosition(this->frogPosition);

	this->stretchingLegs(deltaTime);


}

void Frog::stretchingLegs(float deltaTime)
{
	
}


