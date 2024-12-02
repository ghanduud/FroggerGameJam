#pragma once
#include "AABBCollider.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>

class Particle {
public:
    sf::Vector2f postion;
    sf::RectangleShape shape;
    AABBCollider rectangleCollider;


    Particle() {
        
    }


    void Particle::Update(float dt) {

    }
};
