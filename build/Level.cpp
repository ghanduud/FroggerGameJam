#include "Level.h"
#include <cmath>




Level::Level(TextureLoader& textureLoader) {

    sf::Vector2f frogPosition(400, 80*6+40 );


    Frog frog(frogPosition, 80);
    this->frog = frog;

    for (int i = 0; i < 40; i++) {
        int r = rand() % 3;
        if (r==0) {
            Lane lane(LaneType::resting, sf::Vector2f(800, 80),textureLoader);
            this->lanes.push_back(lane);
        }
        else if (r == 1) {

            Lane lane(LaneType::road, sf::Vector2f(800, 80),textureLoader);
            this->lanes.push_back(lane);
        }
        else if (r == 2) {
            Lane lane(LaneType::water, sf::Vector2f(800, 80),textureLoader);
            this->lanes.push_back(lane);
        }
    }





}


void Level::resetLevel() {

}

void Level::update(float dt, Direction direction) {



    if (this->isGameOver) {
        gameOverTimer += dt;
        if (this->gameOverTimer >= 2.0f) {

            this->resetLevel();

            this->isGameOver = false; 


            this->gameOverTimer = 0.0f; 
        }
        return;
    }






    if (direction == Direction::UP) {
        start += 1;
    }
    else if (direction == Direction::DOWN) {
        start -= 1;
    }









    this->frog.update(dt, direction);

   /* for (Lane& lane : this->lanes) {
        lane.update(dt);
    }*/

    for (Lane& lane : this->lanes) {

        for (MovingPlatform& mp : lane.movingPlatforms) {

            if (frog.frogCollider.checkCollision(mp.platformCollider)) {

                this->frog.isAlive = false;
                this->isGameOver = true;
                return;

            }
        }
    }
}

void Level::renderMap(int sizeOfLanesInWindow, sf::RenderWindow& window)
{
    
		for (int i = 0; i < sizeOfLanesInWindow;i++) {
			lanes[start - 1 + i].render(window, i);
		}
		frog.render(window);

}



