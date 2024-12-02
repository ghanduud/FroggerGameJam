#pragma once
#include "AABBCollider.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>

class MovingOpject {
public:
    sf::Vector2f postion;
    sf::RectangleShape shape;
    AABBCollider rectangleCollider;


    MovingOpject() {
        
    }


    void MovingOpject::Update(float dt) {

    }
};
