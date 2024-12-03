#include "Level.h"
#include <cmath>




Level::Level(TextureLoader& textureLoader) {

    sf::Vector2f frogPosition(440, 80*6+40);


    Frog frog(frogPosition, 80, textureLoader, sf::Vector2f(80, 80));
    this->frog = frog;

    this->frogCurrentLane = start + 4;

    for (int i = 0; i < 9; i++) {
        Lane lane(LaneType::resting, sf::Vector2f(800, 80),textureLoader, i % 2 == 0);
        this->lanes.push_back(lane);

    }
    Lane lane1(LaneType::BLOCK, sf::Vector2f(800, 80), textureLoader, 0);
    this->lanes.push_back(lane1);


    Lane lane2(LaneType::resting, sf::Vector2f(800, 80), textureLoader, 0);
    this->lanes.push_back(lane2);
    Lane lane3(LaneType::resting, sf::Vector2f(800, 80), textureLoader, 0);
    this->lanes.push_back(lane3);
    Lane lane4(LaneType::resting, sf::Vector2f(800, 80), textureLoader, 0);
    this->lanes.push_back(lane4);
    Lane lane5(LaneType::resting, sf::Vector2f(800, 80), textureLoader, 0);
    this->lanes.push_back(lane5);


    for (int i = 0; i < 40; i++) {
        int r = rand() % 3;
        if (r == 0) {
            Lane lane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, i % 2 == 0);
            this->lanes.push_back(lane);
        }
        else if (r == 1) {

            Lane lane(LaneType::road, sf::Vector2f(800, 80), textureLoader, i % 2 == 0);
            this->lanes.push_back(lane);
        }
        else if (r == 2) {


            Lane lane(LaneType::water, sf::Vector2f(800, 80), textureLoader, i % 2 == 0);
            this->lanes.push_back(lane);
        }
    }



}


void Level::resetLevel() {

}

void Level::update(float dt, Direction direction) {

    bool inWater = false;

    /*if (this->isGameOver) {
        gameOverTimer += dt;
        if (this->gameOverTimer >= 2.0f) {

            this->resetLevel();

            this->isGameOver = false; 


            this->gameOverTimer = 0.0f; 
        }
        return;
    }*/

    //std::cout << this->frogCurrentLane << std::endl;




    if (direction == Direction::UP) {
        //if (this->lanes[this->frogCurrentLane + 1].laneType == LaneType::END) {
        //    //this->win();
        //}
        start += 1;   
    }
    if (direction == Direction::DOWN) {
        if (this->lanes[this->frogCurrentLane-1].laneType != LaneType::BLOCK) {    
            start -= 1;
        }

    }

    this->frogCurrentLane = start + 3;

    this->frog.update(dt, direction);


    for (int i = 0; i < lanes.size(); i++)
    {
        lanes[i].update(dt, start, i);
    }

    if (this->lanes[this->frogCurrentLane].laneType == LaneType::water) {
        inWater = true;
    }

    for (Lane& lane : this->lanes) {

        for (MovingPlatform& mp : lane.movingPlatforms) {

            if (frog.frogCollider.checkCollision(mp.platformCollider)) {

                
                //if he collide with any thing make the boo, with true
                inWater = false;
                

                if (this->lanes[this->frogCurrentLane].laneType == LaneType::road) {
                    this->frog.isAlive = false;
                    this->isGameOver = true;
                    return;
                }

                

            }
        }
    }
    if (inWater) {
        this->frog.isAlive = false;
        this->isGameOver = true;
        return;
    }
}

void Level::renderMap(int sizeOfLanesInWindow, sf::RenderWindow& window)
{
    
		for (int i = 0; i < sizeOfLanesInWindow;i++) {
			lanes[start + i].render(window, i);
		}
        for (int i = 0; i < sizeOfLanesInWindow;i++) {
            lanes[start + i].renderObsticals(window);
        }
		frog.render(window);

}



