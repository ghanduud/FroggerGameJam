#include "MovingPlatform.h"
#include "math.h"

MovingPlatform::MovingPlatform(int size, PlatformType type,Direction direction,int x, TextureLoader& textureLoader) {
    platformShape.setSize(sf::Vector2f(80 * size, 80));
	platformdebugShape.setPointCount(4);
	platformdebugShape.setFillColor(sf::Color(255,0,0,100));
    if (type == Hopper) {
        if(size == 3) 
        {
            platformShape.setTexture(&textureLoader.trunkTexture);
        }
        if (size == 2)
        {
            platformShape.setTexture(&textureLoader.leaveTexture);
        }
        if (size == 1)
        {
            platformShape.setTexture(&textureLoader.turtleTexture);
        }
        this->platformCollider.ul = sf::Vector2f(-10, 0);
        this->platformCollider.lr = sf::Vector2f(size * 80 + 10, 80);
	}
	else if (type == Obstical) {
        if (size == 3) {
            platformShape.setTexture(&textureLoader.bigSnakeTexture);
        }
        if (size == 2) {
            platformShape.setTexture(&textureLoader.midSnakeTexture);
        }
        if (size == 1) {
            platformShape.setTexture(&textureLoader.bugTexture);
        }
        this->platformCollider.ul = sf::Vector2f(40, 0);
        this->platformCollider.lr = sf::Vector2f(size * 80 - 40, 80);
	}

    if (direction == RIGHT)
    {
        platformShape.setPosition(x - platformShape.getSize().x, 0);
		//platformdebugShape.setPosition(x - platformShape.getSize().x, 0);
    }
    if (direction == LEFT)
    {
        platformShape.setPosition(800 + x, 0);
		//platformdebugShape.setPosition(800 + x, 0);
    }
    platformSize = size;
    platformType = type;
 
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

    platformShape.setPosition(sf::Vector2f(newXPosition, laneYPosition));
    platformCollider.updatePosition(platformShape.getPosition());
	makedebugshape(platformdebugShape, platformCollider.ul, platformCollider.lr);
}

void MovingPlatform::render(sf::RenderWindow& window)
{
    window.draw(platformShape);
	if(debug) window.draw(platformdebugShape);
}

void MovingPlatform::makedebugshape(sf::ConvexShape& shape, sf::Vector2f ul, sf::Vector2f lr) {
	shape.setPoint(0, ul);
	shape.setPoint(1, sf::Vector2f(lr.x, ul.y));
	shape.setPoint(2, lr);
	shape.setPoint(3, sf::Vector2f(ul.x, lr.y));
}