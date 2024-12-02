#include "Lane.h"

Lane::Lane(LaneType type, sf::Vector2f size,TextureLoader& textureLoader) {
    // Load texture
    /*if (!this->landTexture.loadFromFile("../resources/land.png")) {
        std::cerr << "Error loading texture!" << std::endl;
    }*/
    
    landSprit.setTextureRect(sf::Rect(0, 0, (int)(textureLoader.landTexture.getSize().x * size.x / size.y), (int)textureLoader.landTexture.getSize().y));
    landSprit.setScale(sf::Vector2f(size.y/textureLoader.landTexture.getSize().x, size.y / textureLoader.landTexture.getSize().y));
    

    laneType = type;
    laneTile.setSize(size);
    
    switch (type) {
    case resting:
        laneTile.setFillColor(sf::Color::Green);
        break;
    case road:
        laneTile.setTexture(&textureLoader.landTexture);
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
	//landSprit.setPosition(sf::Vector2f(0, (9 - index) * laneTile.getSize().y));
    laneTile.setPosition(sf::Vector2f(0, (9 - index) * laneTile.getSize().y));
    //window.draw(landSprit);
    window.draw(laneTile);
}