#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(sf::Vector2f position, sf::RectangleShape shape, sf::Vector2f size, PlatformType type) {
    platformPostion = position;
    platformShape = shape;
    platformCollider.position = position;
    platformCollider.ul = position - size / 2.f;
    platformCollider.lr = position + size / 2.f;
    platformSize = size;
    platformType = type;
}

void MovingPlatform::update(float dt, sf::Vector2f speed) {
    platformPostion += speed * dt;
    platformShape.setPosition(platformPostion);
    platformCollider.updatePosition(platformPostion);
}

void MovingPlatform::render(sf::RenderWindow& window)
{
    window.draw(platformShape);
}