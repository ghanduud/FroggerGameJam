#include "Level.h"
#include <cmath>




Level::Level(TextureLoader& textureLoader) {
    // Set initial frog position
    sf::Vector2f frogPosition(440, 80 * 6 + 40);
    Frog frog(frogPosition, 80, textureLoader, sf::Vector2f(80, 80));
    this->frog = frog;
    this->frogCurrentLane = start + 4;

    // 10 resting lanes
    for (int i = 0; i < 10; i++) {
        Lane lane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 10);
        this->lanes.push_back(lane);
    }

    // Block lane
    Lane blockLane(LaneType::BLOCK, sf::Vector2f(800, 80), textureLoader, false, 50);
    this->lanes.push_back(blockLane);

    // 5 resting lanes
    for (int i = 0; i < 5; i++) {
        Lane lane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 60);
        this->lanes.push_back(lane);
    }

    // Alternating water/road lanes separated by resting lanes
    for (int i = 0; i < 20; i++) { // Total 20 lanes (10 water, 10 road)
        // Resting lane before water/road
		int chance = rand() % 3;
		if (chance == 0) {
			Lane restingLane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 70);
			this->lanes.push_back(restingLane);
		}
        else if (chance == 1) {
            Lane waterLane(LaneType::water, sf::Vector2f(800, 80), textureLoader, i % 2 == 0, 80 + (rand() % 11) * 5);
            this->lanes.push_back(waterLane);
        }
        else
        {
            Lane roadLane(LaneType::road, sf::Vector2f(800, 80), textureLoader, i % 2 == 0, 80 + (rand() % 11) * 5);
            this->lanes.push_back(roadLane);
        }
        //Lane restingLane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 70);
        //this->lanes.push_back(restingLane);

        //if (i % 2 == 0) {
        //    // Water lane
        //    Lane waterLane(LaneType::water, sf::Vector2f(800, 80), textureLoader, i % 2 == 0, 80 + (rand() % 11) * 5);
        //    this->lanes.push_back(waterLane);
        //}
        //else {
        //    // Road lane
        //    Lane roadLane(LaneType::road, sf::Vector2f(800, 80), textureLoader, i % 2 == 0, 80 + (rand() % 11) * 5);
        //    this->lanes.push_back(roadLane);
        //}


    }

    // Final resting lane
    Lane finalRestingLane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 15);
    this->lanes.push_back(finalRestingLane);

    // END lane
    Lane endLane(LaneType::END, sf::Vector2f(800, 80), textureLoader, false, 0);
    this->lanes.push_back(endLane);

    // 10 resting lanes
    for (int i = 0; i < 10; i++) {
        Lane lane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 10);
        this->lanes.push_back(lane);
    }
    // 10 resting lanes
    for (int i = 0; i < 10; i++) {
        Lane lane(LaneType::resting, sf::Vector2f(800, 80), textureLoader, false, 10);
        this->lanes.push_back(lane);
    }

}



void Level::resetLevel(TextureLoader& textureLoader) {
    // Set initial frog position
    sf::Vector2f frogPosition(440, 80 * 6 + 40);
    Frog frog(frogPosition, 80, textureLoader, sf::Vector2f(80, 80));
    this->frog = frog;
    this->frogCurrentLane = start + 4;


    this->score = 0;
    this->start = 10;

    this->isGameOver = false;
    this->gameOverTimer = 0.0f;
}

void Level::winGame(TextureLoader& textureLoader) {
    resetLevel(textureLoader);
}

void Level::update(float dt, Direction direction, TextureLoader& textureLoader) {

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

        float speed = this->lanes[this->frogCurrentLane].laneSpeed;
        if (this->lanes[this->frogCurrentLane].laneDirection == LEFT) {
            speed *= -1;
        }

        this->frog.frogOnWater(speed, dt);

    }

    if (this->lanes[this->frogCurrentLane].laneType == LaneType::END) {
        winGame(textureLoader);
        std::cout << "win the game" << std::endl;
        return;

    }

    //for (Lane& lane : this->lanes) {

        for (MovingPlatform& mp : lanes[frogCurrentLane].movingPlatforms) {

            if (frog.frogCollider.checkCollision(mp.platformCollider)) {

                
                //if he collide with any thing make the boo, with true
                inWater = false;
                

                if (this->lanes[this->frogCurrentLane].laneType == LaneType::road) {

                    std::cout << "die" << std::endl;
                    resetLevel(textureLoader);
                }

                

            }
        }
    //}
    if (inWater) {

        std::cout << "die" << std::endl;
        resetLevel(textureLoader);
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



