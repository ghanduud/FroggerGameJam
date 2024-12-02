#include "Game.h"


void Game::addMovingPlatform(MovingPlatform* particle) {
	this->particles.push_back(particle);
}

void Game::Update(float deltaTime) {
    for (MovingPlatform* particle : this->particles) {
        particle->Update(deltaTime);


        for (MovingPlatform* otherParticle : this->particles) {
            if (particle == otherParticle) {
                continue;
            }

            if (particle->rectangleCollider.checkCollision(otherParticle->rectangleCollider)) {
                
            }
     

        }
    }
}
