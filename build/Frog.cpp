#include "Frog.h"

Frog::Frog()
{
}

Frog::Frog(sf::Vector2f Position, float laneHeight, TextureLoader& textureLoader, sf::Vector2f size)
{

	// set the frog to the middle of the 5th lane
	this->frogPosition = Position;
	this->frogSize = laneHeight;

	this->frogVelocity = 80.f*60;

	this->isAlive = true;
	this->isJumping = false;
	this->frogDirection = UP;

	this->frogCollider.position = Position;
	this->frogCollider.ul = Position - sf::Vector2f(this->frogSize, this->frogSize) / 2.f;
	this->frogCollider.lr = Position + sf::Vector2f(this->frogSize, this->frogSize) / 2.f;

	// testing frog
	this->frogShapeTest.setFillColor(sf::Color::Red);
	this->frogShapeTest.setOrigin(laneHeight / 2, laneHeight / 2);
	this->frogShapeTest.setPosition(Position);
	this->frogShapeTest.setSize(sf::Vector2f(laneHeight, laneHeight));
	this->frogShapeTest.setRotation(270.f);


	// Initialize sprite
	this->frogSprite.setTexture(textureLoader.frogStandingTexture);
	this->frogSprite.setOrigin(textureLoader.frogStandingTexture.getSize().x / 2, textureLoader.frogStandingTexture.getSize().y / 2);
	this->frogSprite.setTextureRect(sf::IntRect(0, 0,
		(int)textureLoader.frogStandingTexture.getSize().x,
		(int)textureLoader.frogStandingTexture.getSize().y));
	this->frogSprite.setPosition(Position);
	this->frogSprite.setScale(sf::Vector2f(size.y / textureLoader.frogStandingTexture.getSize().x, size.y / textureLoader.frogStandingTexture.getSize().y));

	
	

	sf::Sprite frogSprite; // the used sprite
	sf::Sprite frogJumpingSprite;
	sf::Sprite frogStandingSprite;
}


bool Frog::isDead()
{
	return (!isAlive);
}

void Frog::death()
{
	this->isAlive = false;
}

bool Frog::isOutOfScreenBounds(sf::Vector2f newPosition,int screenWidth, int screenHeight)
{
	if ((newPosition.x - (0.5 * this->frogSize) <= 0) || // left bound
		(newPosition.x + (0.5 * this->frogSize) >= screenWidth) || // right bound
		(newPosition.y - (0.5 * this->frogSize) <= 0) || // upper bound not possible
		(newPosition.y + (0.5 * this->frogSize) >= screenHeight)) // lower bound not possible
	{
		return true;
	}

	return false;
}

void Frog::render(sf::RenderWindow& window)
{
	//window.draw(this->frogShapeTest);
	window.draw(this->frogSprite);
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
	
		
		if (this->frogSprite.getRotation() != 0)
			this->frogSprite.setRotation(0);

	}
	if (Dir == Direction::DOWN) 
	{
		//this->frogPosition.y += deltaTime * frogVelocity;

		this->frogDirection = DOWN;

		if (this->frogSprite.getRotation() != 180)
			this->frogSprite.setRotation(180);

	}
	if (Dir == Direction::LEFT) 
	{
		sf::Vector2f newPosition = sf::Vector2f(this->frogPosition.x - deltaTime * frogVelocity,frogPosition.y);
		if (!isOutOfScreenBounds(newPosition, 800, 800)) frogPosition = newPosition;

		this->frogDirection = LEFT;

		if (this->frogSprite.getRotation() != 270)
			this->frogSprite.setRotation(270);

	}
	if (Dir == Direction::RIGHT) 
	{
		sf::Vector2f newPosition = sf::Vector2f(this->frogPosition.x+ deltaTime * frogVelocity, frogPosition.y );
		if (!isOutOfScreenBounds(newPosition, 800, 800)) frogPosition = newPosition;

		this->frogDirection = RIGHT;

		if (this->frogSprite.getRotation() != 90)
			this->frogSprite.setRotation(90);

	}

	// TEST: updating sfml rectangle to test!
	//this->frogSprite.setPosition(this->frogPosition);

	// updating the frog AABB collider
	this->frogCollider.updatePosition(this->frogPosition);

	// calling the function that makes the frog jump animation
	this->stretchingLegs(deltaTime);

	// updating the sprite position
	this->frogSprite.setPosition(this->frogPosition);
}

void Frog::stretchingLegs(float deltaTime)
{
	
}


