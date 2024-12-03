#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(int size, PlatformType type,Direction direction) {
    platformShape.setSize(sf::Vector2f(80 * size, 80));
    if (direction == RIGHT) platformShape.setPosition(-platformShape.getSize().x, 0);
    if (direction == LEFT) platformShape.setPosition(800, 0);
    platformShape.setPosition(0, 700);
    platformSize = size;
    platformType = type;
    this->platformCollider.ul = sf::Vector2f(0, 0);
    this->platformCollider.lr = sf::Vector2f(size * 80, 80);
}

void MovingPlatform::update(float dt, float speed,float laneYPosition) {
    platformShape.setPosition(sf::Vector2f(platformShape.getPosition().x + speed * dt, laneYPosition));
    platformCollider.updatePosition(platformShape.getPosition());
}

void MovingPlatform::render(sf::RenderWindow& window)
{
    window.draw(platformShape);
}