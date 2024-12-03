#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(int size, PlatformType type,Direction direction,int x) {
    platformShape.setSize(sf::Vector2f(80 * size, 80));
    if (direction == RIGHT) platformShape.setPosition(x-platformShape.getSize().x, 0);
    if (direction == LEFT) platformShape.setPosition(800+x, 0);
    platformSize = size;
    platformType = type;
    this->platformCollider.ul = sf::Vector2f(0, 0);
    this->platformCollider.lr = sf::Vector2f(size * 80, 80);
    if (direction == LEFT) {
        directionOfPlatform = -1;
    }
    else {
        directionOfPlatform = 1;
    }
}

void MovingPlatform::update(float dt, float speed,float laneYPosition) {

    platformShape.setPosition(sf::Vector2f(platformShape.getPosition().x + (speed * directionOfPlatform) * dt, laneYPosition));
    platformCollider.updatePosition(platformShape.getPosition());
}

void MovingPlatform::render(sf::RenderWindow& window)
{
    window.draw(platformShape);
}