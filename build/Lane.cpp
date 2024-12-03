#include "Lane.h"

Lane::Lane(LaneType type, sf::Vector2f size, TextureLoader& textureLoader, bool isInverted) {
    // Calculate the texture rectangle and scale
    landSprit.setTextureRect(sf::IntRect(0, 0,
        (int)textureLoader.landTexture.getSize().x * size.x / size.y,
        (int)textureLoader.landTexture.getSize().y));
    landSprit.setScale(sf::Vector2f(size.y / textureLoader.landTexture.getSize().x, size.y / textureLoader.landTexture.getSize().y));

    laneType = type;
    laneTile.setSize(size);
    laneDirection = LEFT;
    if (rand() % 2 == 0) laneDirection = RIGHT;
    
    switch (type) {
    case resting:
        laneDirection = NONE;
        laneTile.setFillColor(sf::Color::Blue);
        break;
    case road:
        landSprit.setTexture(textureLoader.landTexture);
        break;
    case water:
        landSprit.setTexture(textureLoader.waterTexture);
        if (isInverted) {
            sf::Vector2f currentScale = landSprit.getScale();
            landSprit.setScale(currentScale.x, -currentScale.y);
            landSprit.setOrigin(0, landSprit.getTextureRect().height);
        }
        break;
    case BLOCK:
        landSprit.setTexture(textureLoader.blockTexture);
        break;
    case END:
        landSprit.setTexture(textureLoader.waterTexture);
        break;
    default:
        break;
    }
}



void Lane::render(sf::RenderWindow& window, int index)
{
	landSprit.setPosition(sf::Vector2f(0, (9 - index) * 80));
    //laneTile.setPosition(sf::Vector2f(0, (9 - index) * laneTile.getSize().y));
    window.draw(landSprit);
    //window.draw(laneTile);
}