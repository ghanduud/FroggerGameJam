#include "Lane.h"

Lane::Lane(LaneType type, sf::Vector2f size) {
    // Load texture
    if (!this->landTexture.loadFromFile("../resources/land.png")) {
        std::cerr << "Error loading texture!" << std::endl;
    }

    laneType = type;
    laneTile.setSize(size);

    switch (type) {
    case resting:
        laneTile.setTexture(&landTexture);
        break;
    case road:
        laneTile.setFillColor(sf::Color::Color(60, 60, 60, 255));
        break;
    case water:
        laneTile.setFillColor(sf::Color::Blue);
        break;
    default:
        break;
    }
}


void Lane::render(sf::RenderWindow& window, int index)
{
	laneTile.setPosition(sf::Vector2f(0, (9 - index) * laneTile.getSize().y));
	window.draw(laneTile);
}