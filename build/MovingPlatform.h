#pragma once
#include "AABBCollider.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>

class MovingPlatform {
public:
    sf::Vector2f postion;
    sf::RectangleShape shape;
    AABBCollider rectangleCollider;


    MovingPlatform() {
        
    }


    void MovingPlatform::Update(float dt) {

    }
};
