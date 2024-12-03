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

    sf::Sprite platformSprite;
    AABBCollider platformCollider;
    int platformSize;
    PlatformType platformType;
    int directionOfPlatform;


    MovingPlatform(int size, PlatformType type, Direction direction, int x, TextureLoader& textureLoader);

    void update(float dt, float speed, float laneYPosition, float totalsize);

    void render(sf::RenderWindow& window);
};
