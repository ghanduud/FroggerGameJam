#include "Lane.h"

Lane::Lane(LaneType type, sf::Vector2f size,TextureLoader textureLoader) {
    // Load texture
    /*if (!this->landTexture.loadFromFile("../resources/land.png")) {
        std::cerr << "Error loading texture!" << std::endl;
    }*/
    landTexture = &(textureLoader.landTexture);
    landTexture->setRepeated(true);
    landSprit.setTextureRect(sf::Rect(0, 0, (int)(landTexture->getSize().x * size.x / size.y), (int)landTexture->getSize().y));
    landSprit.setScale(sf::Vector2f(size.y/landTexture->getSize().x, size.y / landTexture->getSize().y));
    

    laneType = type;
    laneTile.setSize(size);
    
    switch (type) {
    case resting:
        landSprit.setTexture(*landTexture);
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
	landSprit.setPosition(sf::Vector2f(0, (9 - index) * laneTile.getSize().y));
    laneTile.setPosition(sf::Vector2f(0, (9 - index) * laneTile.getSize().y));
    window.draw(landSprit);
    //window.draw(laneTile);
}