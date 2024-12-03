#include "MovingPlatform.h"
#include "math.h"

MovingPlatform::MovingPlatform(int size, PlatformType type,Direction direction,int x, TextureLoader& textureLoader) {
    /*platformShape.setSize(sf::Vector2f(80 * size, 80));
    if (direction == RIGHT) platformShape.setPosition(x-platformShape.getSize().x, 0);
    if (direction == LEFT) platformShape.setPosition(800+x, 0);
    platformSize = size;
    platformType = type;
    this->platformCollider.ul = sf::Vector2f(0, 0);
    this->platformCollider.lr = sf::Vector2f(size * 80, 80);
    if (direction == LEFT) {
        directionOfPlatform = -1;
    }
    else {
        directionOfPlatform = 1;
    }*/

    this->platformSprite.setTexture(textureLoader.bigSnakeTexture);
    this->platformSprite.setTextureRect(sf::IntRect(0, 0,
        textureLoader.bigSnakeTexture.getSize().x,
        textureLoader.bigSnakeTexture.getSize().y
    ));
    this->platformSprite.setTextureRect(sf::IntRect(0, 0,
        (int)textureLoader.bigSnakeTexture.getSize().x*3,
        (int)textureLoader.bigSnakeTexture.getSize().y));
    if (direction == RIGHT) platformSprite.setPosition(x - platformShape.getSize().x, 0);
    if (direction == LEFT) platformSprite.setPosition(800 + x, 0);
    this->platformSprite.setScale(
        sf::Vector2f(
            (80.f * size) / textureLoader.bigSnakeTexture.getSize().x,
            80.f / textureLoader.bigSnakeTexture.getSize().y
        )
    );

    platformSize = size;
    platformType = type;
    this->platformCollider.ul = sf::Vector2f(0, 0);
    this->platformCollider.lr = sf::Vector2f(size * 80, 80);
    if (direction == LEFT) {
        directionOfPlatform = -1;
    }
    else {
        directionOfPlatform = 1;
    }
}

void MovingPlatform::update(float dt, float speed,float laneYPosition,float totalsize) {
    if (speed == 0)return;
    float newXPosition = platformShape.getPosition().x + (speed * directionOfPlatform) * dt;
    if (speed>0&&newXPosition>totalsize-platformSize*80) newXPosition = -platformSize*80;
    else if(speed<0&&newXPosition<800-totalsize){
        newXPosition = 800;
    }
    //std::cout << newXPosition << "\n";
    platformShape.setPosition(sf::Vector2f(newXPosition, laneYPosition));
    platformCollider.updatePosition(platformShape.getPosition());
}

void MovingPlatform::render(sf::RenderWindow& window)
{
    window.draw(platformSprite);
}