#pragma once
#include <SFML/Graphics.hpp>

static bool debug = false;

class AABBCollider {
public:
    sf::Vector2f ul;   
    sf::Vector2f lr;     
    sf::Vector2f position;



    void updatePosition(sf::Vector2f newPosition) {
        sf::Vector2f offset = newPosition - position;
        ul += offset;
        lr += offset;
        position = newPosition;
    }


    bool checkCollision(AABBCollider other) {
        return !(lr.x < other.ul.x ||
            ul.x > other.lr.x ||
            lr.y < other.ul.y ||
            ul.y > other.lr.y);
    }
};
