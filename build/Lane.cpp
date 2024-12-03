#include "Lane.h"

Lane::Lane(LaneType type, sf::Vector2f size, TextureLoader& textureLoader, bool isInverted) {
    

    laneType = type;
    laneTile.setSize(size);
    laneDirection = LEFT;
    if (rand() % 2 == 0) laneDirection = RIGHT;
    
    switch (type) {
    case resting:
        this->setSpritToLane(textureLoader.restTexture,size,0, textureLoader.landTexture);
        laneDirection = NONE;
        break;
    case road:
        this->setSpritToLane(textureLoader.landTexture,size,0, textureLoader.landTexture);
        for (int i = 0;i < 7;i++) {
            MovingPlatform platform(i%3+1, Obstical,laneDirection);
            this->movingPlatforms.push_back(platform);
        }
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

void Lane::renderObsticals(sf::RenderWindow& window)
{
    for (MovingPlatform mp : this->movingPlatforms) {
        window.draw(mp.platformShape);
    }
}




void Lane::setSpritToLane(sf::Texture& texture, sf::Vector2f size, bool isWater, sf::Texture& landTexture) {






        this->landSprit.setTextureRect(sf::IntRect(0, 0,
            (int)texture.getSize().x * size.x / size.y,
            (int)texture.getSize().y));
        this->landSprit.setScale(sf::Vector2f(size.y / texture.getSize().x, size.y / texture.getSize().y));
        landSprit.setTexture(texture);

}


sf::RectangleShape Lane::setObsticalShape(int number) {
    if (number % 3 == 0) {
        return sf::RectangleShape(sf::Vector2f(80 * 3, 80));
    }
    else if (number % 2 == 0) {
        return sf::RectangleShape(sf::Vector2f(80 * 2, 80));
    }
    else {
        return sf::RectangleShape(sf::Vector2f(80, 80));
    }
}





void Lane::update(float deltaTime,int start,int index) {
    int Ypos = 800 + 80 * (start - index - 1);
    for (int i = 0; i < movingPlatforms.size(); i++)
    {
        movingPlatforms[i].update(deltaTime, 0, Ypos);
    }
}