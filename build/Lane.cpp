#include "Lane.h"

Lane::Lane(LaneType type, sf::Vector2f size, TextureLoader& textureLoader, bool isInverted) {
    

    laneType = type;
    laneTile.setSize(size);
    
    switch (type) {
    case resting:
        this->setSpritToLane(textureLoader.restTexture,size,0, textureLoader.landTexture);
        break;
    case road:
        this->setSpritToLane(textureLoader.landTexture,size,0, textureLoader.landTexture);
        break;
    case water:
        this->setSpritToLane(textureLoader.waterTexture,size,1, textureLoader.landTexture);
        if (isInverted) {
            std::cout << isInverted << std::endl;
            sf::Vector2f currentScale = landSprit.getScale();
            landSprit.setScale(currentScale.x, -currentScale.y);
            landSprit.setOrigin(0, landSprit.getTextureRect().height);
        }
        break;
    case BLOCK:
        this->setSpritToLane(textureLoader.blockTexture, size,0, textureLoader.landTexture);
        break;
    case END:
        this->setSpritToLane(textureLoader.blockTexture, size,1, textureLoader.landTexture);
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




void Lane::setSpritToLane(sf::Texture& texture, sf::Vector2f size, bool isWater, sf::Texture& landTexture) {

    if (isWater) {
        this->landSprit.setTextureRect(sf::IntRect(0, 0,
            (int)landTexture.getSize().x * size.x / size.y,
            (int)landTexture.getSize().y));
        this->landSprit.setScale(sf::Vector2f(size.y / landTexture.getSize().x, size.y / landTexture.getSize().y));
        landSprit.setTexture(texture);
    }
    else {



        this->landSprit.setTextureRect(sf::IntRect(0, 0,
            (int)texture.getSize().x * size.x / size.y,
            (int)texture.getSize().y));
        this->landSprit.setScale(sf::Vector2f(size.y / texture.getSize().x, size.y / texture.getSize().y));
        landSprit.setTexture(texture);
    }
}