#include "Frog.h"



Frog::Frog()
{
}

Frog::Frog(sf::Vector2f Position, float laneHeight, TextureLoader& textureLoader, sf::Vector2f size)
{

	// set the frog to the middle of the 5th lane
	this->frogPosition = Position;
	this->frogSize = laneHeight;

	this->frogVelocity = 80.f * 60;

	this->isAlive = true;
	this->isJumping = false;
	this->frogDirection = UP;

	this->frogCollider.position = Position;
	this->frogCollider.ul = Position - sf::Vector2f(this->frogSize, this->frogSize) / 2.0f;
	this->frogCollider.lr = Position + sf::Vector2f(this->frogSize, this->frogSize) / 2.0f;

	// testing frog
	this->frogShapeTest.setFillColor(sf::Color(0,0,255,100));
	this->frogShapeTest.setPointCount(4);
	makedebugshape(frogShapeTest, frogCollider.ul, frogCollider.lr);
	//this->frogShapeTest.setOrigin(laneHeight / 2, laneHeight / 2);
	//this->frogShapeTest.setPosition(Position);
	//this->frogShapeTest.setSize(sf::Vector2f(laneHeight, laneHeight));
	//this->frogShapeTest.setRotation(270.f);


	// Initialize sprite
	this->frogSprite.setTexture(textureLoader.frogStandingTexture);
	this->frogSprite.setOrigin(textureLoader.frogStandingTexture.getSize().x / 2, textureLoader.frogStandingTexture.getSize().y / 2);
	this->frogSprite.setTextureRect(sf::IntRect(0, 0,
		(int)textureLoader.frogStandingTexture.getSize().x,
		(int)textureLoader.frogStandingTexture.getSize().y));
	this->frogSprite.setPosition(Position);
	this->frogSprite.setScale(sf::Vector2f(size.y / textureLoader.frogStandingTexture.getSize().x, size.y / textureLoader.frogStandingTexture.getSize().y));




	// Initialize jumping sprite
	this->JumpingSprite.setTexture(textureLoader.frogJumpingTexture);
	this->JumpingSprite.setOrigin(textureLoader.frogJumpingTexture.getSize().x / 2, textureLoader.frogJumpingTexture.getSize().y / 2);
	this->JumpingSprite.setTextureRect(sf::IntRect(0, 0,
		(int)textureLoader.frogJumpingTexture.getSize().x,
		(int)textureLoader.frogJumpingTexture.getSize().y));
	this->JumpingSprite.setPosition(Position.x + 10, Position.y + 10); // change back

	//this->JumpingSprite.setScale(sf::Vector2f(size.y / textureLoader.frogJumpingTexture.getSize().x, size.y / textureLoader.frogJumpingTexture.getSize().y));
	this->JumpingSprite.setScale(sf::Vector2f((size.y *1) / textureLoader.frogJumpingTexture.getSize().x, (size.y * 1200/710) / textureLoader.frogJumpingTexture.getSize().y));



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

bool Frog::isOutOfScreenBounds(sf::Vector2f newPosition, int screenWidth, int screenHeight)
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
	window.draw(this->frogSprite);
	if(debug) window.draw(this->frogShapeTest);
	//window.draw(this->JumpingSprite);
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
		sf::Vector2f newPosition = sf::Vector2f(this->frogPosition.x - deltaTime * frogVelocity, frogPosition.y);
		if (!isOutOfScreenBounds(newPosition, 800, 800)) frogPosition = newPosition;

		this->frogDirection = LEFT;

		if (this->frogSprite.getRotation() != 270)
			this->frogSprite.setRotation(270);

	}
	if (Dir == Direction::RIGHT)
	{
		sf::Vector2f newPosition = sf::Vector2f(this->frogPosition.x + deltaTime * frogVelocity, frogPosition.y);
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
	makedebugshape(frogShapeTest, frogCollider.ul, frogCollider.lr);
}

void Frog::stretchingLegs(float deltaTime)
{

}



void Frog::frogOnWater(float speed ,float dt) {
	sf::Vector2f newPosition = sf::Vector2f(this->frogPosition.x - dt * ( - speed), frogPosition.y);
	if (!isOutOfScreenBounds(newPosition, 800, 800)) frogPosition = newPosition;

	// updating the frog AABB collider
	this->frogCollider.updatePosition(this->frogPosition);

	// calling the function that makes the frog jump animation
	this->stretchingLegs(dt);

	// updating the sprite position
	this->frogSprite.setPosition(this->frogPosition);
	makedebugshape(frogShapeTest, frogCollider.ul, frogCollider.lr);
}

void Frog::makedebugshape(sf::ConvexShape& shape, sf::Vector2f ul, sf::Vector2f lr)
{
	shape.setPoint(0, ul);
	shape.setPoint(1, sf::Vector2f(lr.x, ul.y));
	shape.setPoint(2, lr);
	shape.setPoint(3, sf::Vector2f(ul.x, lr.y));
}

