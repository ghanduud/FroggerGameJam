#include "Level.h"




Level::Level() {

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

    for (Lane& lane : this->lanes) {
        lane.update(dt);
    }

    for (Lane& lane : this->lanes) {

        for (MovingPlatform& mp : lane.movingPlatform) {

            if (frog.frogCollider.checkCollision(mp.platformCollider)) {

                this->frog.isAlive = false;
                this->isGameOver = true;
                return;

            }
        }
    }
}

void Level::renderMap(int sizeOfLanesInWindow, sf::RenderWindow& window) {
{
		for (int i = 0; i < sizeOfLanesInWindow;i++) {
			lanes[start - 1 + i].render(window, i);
		}

		frog.render(window);
}



