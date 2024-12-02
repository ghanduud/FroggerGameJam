#pragma once
#include "AABBCollider.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>

enum PlatformType
{
    Obstical,
    Hopper
};

class MovingPlatform {
public:
    sf::Vector2f platformPostion;
    sf::RectangleShape platformShape;
    AABBCollider platformCollider;
    sf::Vector2f platformSize;
    PlatformType platformType;


    MovingPlatform(sf::Vector2f position,sf::RectangleShape shape,sf::Vector2f size,PlatformType type) {
        platformPostion = position;
        platformShape = shape;
        platformCollider.position = position;
        platformCollider.ul = position - size / 2.f;
        platformCollider.lr = position + size / 2.f;
        platformSize = size;
        platformType = type;
    }


    void MovingPlatform::Update(float dt) {

    }
};
