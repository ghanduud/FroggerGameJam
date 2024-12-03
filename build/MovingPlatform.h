#pragma once
#include "AABBCollider.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include "Frog.h"

enum PlatformType
{
    Obstical,
    Hopper
};

class MovingPlatform {
public:
    sf::RectangleShape platformShape;
    AABBCollider platformCollider;
    int platformSize;
    PlatformType platformType;
    int directionOfPlatform;


    MovingPlatform(int size, PlatformType type, Direction direction);

    void update(float dt, float speed, float laneYPosition);

    void render(sf::RenderWindow& window);
};
